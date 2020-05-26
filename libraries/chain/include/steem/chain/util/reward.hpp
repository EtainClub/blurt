#pragma once

#include <steem/protocol/asset.hpp>
#include <steem/protocol/config.hpp>
#include <steem/protocol/types.hpp>
#include <steem/protocol/misc_utilities.hpp>

#include <fc/reflect/reflect.hpp>

#include <fc/uint128.hpp>

namespace steem { namespace chain { namespace util {

using steem::protocol::asset;
using steem::protocol::price;
using steem::protocol::share_type;

using fc::uint128_t;

struct comment_reward_context
{
   share_type rshares;
   uint16_t   reward_weight = 0;
   asset      max_payout;
   uint128_t  total_reward_shares2;
   asset      total_reward_fund_steem;
   protocol::curve_id   reward_curve = protocol::quadratic;
   uint128_t  content_constant = STEEM_CONTENT_CONSTANT_HF0;
};

uint64_t get_rshare_reward( const comment_reward_context& ctx );

inline uint128_t get_content_constant_s()
{
   return STEEM_CONTENT_CONSTANT_HF0; // looking good for posters
}

uint128_t evaluate_reward_curve( const uint128_t& rshares, const protocol::curve_id& curve = protocol::quadratic, const uint128_t& var1 = STEEM_CONTENT_CONSTANT_HF0 );

inline bool is_comment_payout_dust( uint64_t steem_payout )
{
   return asset( steem_payout, STEEM_SYMBOL ) < STEEM_MIN_PAYOUT;
}

} } } // steem::chain::util

FC_REFLECT( steem::chain::util::comment_reward_context,
   (rshares)
   (reward_weight)
   (max_payout)
   (total_reward_shares2)
   (total_reward_fund_steem)
   (reward_curve)
   (content_constant)
   )
