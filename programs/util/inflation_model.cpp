
#include <blurt/chain/compound.hpp>
#include <blurt/protocol/asset.hpp>
#include <blurt/protocol/types.hpp>

#include <fc/io/json.hpp>
#include <fc/variant_object.hpp>

#include <iostream>
#include <vector>

#define CURATE_OFF      0
#define VCURATE_OFF     1
#define CONTENT_OFF     2
#define VCONTENT_OFF    3
#define PRODUCER_OFF    4
#define VPRODUCER_OFF   5
#define POW_OFF         6
#define VPOW_OFF        7
#define REWARD_TYPES    8

using blurt::protocol::asset;
using blurt::protocol::share_type;
using blurt::protocol::calc_percent_reward_per_block;
using blurt::protocol::calc_percent_reward_per_round;
using blurt::protocol::calc_percent_reward_per_hour;

/*
Explanation of output

{"rvec":["929159090641","8360617424769","929159090641","8360617424769","197985103985","1780051544865","195077031513","1755693283617","179687790278","1615357001502"],"b":68585000,"s":"24303404786580"}

rvec shows total number of STEEM satoshis created since genesis for:

- Curation rewards
- Vesting rewards balancing curation rewards
- Content rewards
- Vesting rewards balancing content rewards
- Producer rewards
- Vesting rewards balancing producer rewards
- Liquidity rewards
- Vesting rewards balancing liquidity rewards
- PoW rewards
- Vesting rewards balancing PoW rewards

b is block number
s is total supply


Some possible sources of inaccuracy, the direction and estimated relative sizes of these effects:

- Missed blocks not modeled (lowers STEEM supply, small)
- Miner queue length very approximately modeled (assumed to go to 100 during the first blocks and then stay there) (may lower or raise STEEM supply, very small)
- Creation / destruction of STEEM used to back SBD not modeled (moves STEEM supply in direction opposite to changes in dollar value of 1 STEEM, large)
- Interest paid to SBD not modeled (raises STEEM supply, medium)
- Lost / forgotten private keys / wallets and deliberate burning of STEEM not modeled (lowers STEEM supply, unknown but likely small)
- Possible bugs or mismatches with implementation (unknown)

*/

int main( int argc, char** argv, char** envp )
{
   std::vector< share_type > reward_delta;
   std::vector< share_type > reward_total;

/*
#define BLURT_GENESIS_TIME                    (fc::time_point_sec(1458835200))
#define BLURT_MINING_TIME                     (fc::time_point_sec(1458838800))
#define BLURT_FIRST_CASHOUT_TIME              (fc::time_point_sec(1467590400))  /// July 4th
*/

   uint32_t liquidity_begin_block = (1467590400 - 1458835200) / 3;
   uint32_t pow_deficit = 100;

   for( int i=0; i<REWARD_TYPES; i++ )
   {
      reward_delta.emplace_back();
      reward_total.emplace_back();
   }

   auto block_inflation_model = [&]( uint32_t block_num, share_type& current_supply )
   {
      uint32_t vesting_factor = (block_num < BLURT_START_VESTING_BLOCK) ? 0 : 9;

      share_type curate_reward   = calc_percent_reward_per_block< BLURT_CURATE_APR_PERCENT >( current_supply );
      reward_delta[ CURATE_OFF ] = std::max( curate_reward, BLURT_MIN_CURATE_REWARD.amount );
      reward_delta[ VCURATE_OFF ] = reward_delta[ CURATE_OFF ] * vesting_factor;

      share_type content_reward  = calc_percent_reward_per_block< BLURT_CONTENT_APR_PERCENT >( current_supply );
      reward_delta[ CONTENT_OFF ] = std::max( content_reward, BLURT_MIN_CONTENT_REWARD.amount );
      reward_delta[ VCONTENT_OFF ] = reward_delta[ CONTENT_OFF ] * vesting_factor;

      share_type producer_reward = calc_percent_reward_per_block< BLURT_PRODUCER_APR_PERCENT >( current_supply );
      reward_delta[ PRODUCER_OFF ] = std::max( producer_reward, BLURT_MIN_PRODUCER_REWARD.amount );
      reward_delta[ VPRODUCER_OFF ] = reward_delta[ PRODUCER_OFF ] * vesting_factor;

      current_supply += reward_delta[CURATE_OFF] + reward_delta[VCURATE_OFF] + reward_delta[CONTENT_OFF] + reward_delta[VCONTENT_OFF] + reward_delta[PRODUCER_OFF] + reward_delta[VPRODUCER_OFF];
      // supply for above is computed by using pre-updated supply for computing all 3 amounts.
      // supply for below reward types is basically a self-contained event which updates the supply immediately before the next reward type's computation.

      share_type pow_reward = 0;

      if( (block_num % BLURT_MAX_WITNESSES) == 0 )
         ++pow_deficit;

      if( pow_deficit > 0 )
      {
         pow_reward = calc_percent_reward_per_round< BLURT_POW_APR_PERCENT >( current_supply );
         pow_reward = std::max( pow_reward, BLURT_MIN_POW_REWARD.amount );
         if( block_num < BLURT_START_MINER_VOTING_BLOCK )
            pow_reward *= BLURT_MAX_WITNESSES;
         --pow_deficit;
      }
      reward_delta[ POW_OFF ] = pow_reward;
      reward_delta[ VPOW_OFF ] = reward_delta[ POW_OFF ] * vesting_factor;

      current_supply += reward_delta[ POW_OFF ] + reward_delta[ VPOW_OFF ];

      for( int i=0; i<REWARD_TYPES; i++ )
      {
         reward_total[i] += reward_delta[i];
      }

      return;
   };

   share_type current_supply = 0;

   for( uint32_t b=1; b<10*BLURT_BLOCKS_PER_YEAR; b++ )
   {
      block_inflation_model( b, current_supply );
      if( b%1000 == 0 )
      {
         fc::mutable_variant_object mvo;
         mvo("rvec", reward_total)("b", b)("s", current_supply);
         std::cout << fc::json::to_string(mvo) << std::endl;
      }
   }

   return 0;
}
