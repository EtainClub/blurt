#include <blurt/protocol/get_config.hpp>
#include <blurt/protocol/config.hpp>
#include <blurt/protocol/asset.hpp>
#include <blurt/protocol/types.hpp>
#include <blurt/protocol/version.hpp>

namespace blurt { namespace protocol {

fc::variant_object get_config()
{
   fc::mutable_variant_object result;

#ifdef IS_TEST_NET
   result[ "IS_TEST_NET" ] = true;
   result["TESTNET_BLOCK_LIMIT"] = TESTNET_BLOCK_LIMIT;
#else
   result[ "IS_TEST_NET" ] = false;
#endif
   result["BLURT_REDUCED_VOTE_POWER_RATE"] = BLURT_REDUCED_VOTE_POWER_RATE;
   result["BLURT_100_PERCENT"] = BLURT_100_PERCENT;
   result["BLURT_1_PERCENT"] = BLURT_1_PERCENT;
   result["BLURT_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD"] = BLURT_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD;
   result["BLURT_ACTIVE_CHALLENGE_COOLDOWN"] = BLURT_ACTIVE_CHALLENGE_COOLDOWN;
   result["BLURT_ACTIVE_CHALLENGE_FEE"] = BLURT_ACTIVE_CHALLENGE_FEE;
   result["BLURT_ADDRESS_PREFIX"] = BLURT_ADDRESS_PREFIX;
   result["BLURT_APR_PERCENT_MULTIPLY_PER_BLOCK"] = BLURT_APR_PERCENT_MULTIPLY_PER_BLOCK;
   result["BLURT_APR_PERCENT_MULTIPLY_PER_HOUR"] = BLURT_APR_PERCENT_MULTIPLY_PER_HOUR;
   result["BLURT_APR_PERCENT_MULTIPLY_PER_ROUND"] = BLURT_APR_PERCENT_MULTIPLY_PER_ROUND;
   result["BLURT_APR_PERCENT_SHIFT_PER_BLOCK"] = BLURT_APR_PERCENT_SHIFT_PER_BLOCK;
   result["BLURT_APR_PERCENT_SHIFT_PER_HOUR"] = BLURT_APR_PERCENT_SHIFT_PER_HOUR;
   result["BLURT_APR_PERCENT_SHIFT_PER_ROUND"] = BLURT_APR_PERCENT_SHIFT_PER_ROUND;
   result["BLURT_BANDWIDTH_AVERAGE_WINDOW_SECONDS"] = BLURT_BANDWIDTH_AVERAGE_WINDOW_SECONDS;
   result["BLURT_BANDWIDTH_PRECISION"] = BLURT_BANDWIDTH_PRECISION;
   result["BLURT_BENEFICIARY_LIMIT"] = BLURT_BENEFICIARY_LIMIT;
   result["BLURT_BLOCKCHAIN_PRECISION"] = BLURT_BLOCKCHAIN_PRECISION;
   result["BLURT_BLOCKCHAIN_PRECISION_DIGITS"] = BLURT_BLOCKCHAIN_PRECISION_DIGITS;
   result["BLURT_BLOCKCHAIN_HARDFORK_VERSION"] = BLURT_BLOCKCHAIN_HARDFORK_VERSION;
   result["BLURT_BLOCKCHAIN_VERSION"] = BLURT_BLOCKCHAIN_VERSION;
   result["BLURT_BLOCK_INTERVAL"] = BLURT_BLOCK_INTERVAL;
   result["BLURT_BLOCKS_PER_DAY"] = BLURT_BLOCKS_PER_DAY;
   result["BLURT_BLOCKS_PER_HOUR"] = BLURT_BLOCKS_PER_HOUR;
   result["BLURT_BLOCKS_PER_YEAR"] = BLURT_BLOCKS_PER_YEAR;
   result["BLURT_CASHOUT_WINDOW_SECONDS"] = BLURT_CASHOUT_WINDOW_SECONDS;
   result["BLURT_CHAIN_ID"] = BLURT_CHAIN_ID;
   result["BLURT_COMMENT_TITLE_LIMIT"] = BLURT_COMMENT_TITLE_LIMIT;
   result["BLURT_CONTENT_CONSTANT_HF21"] = BLURT_CONTENT_CONSTANT_HF21;
   result["BLURT_CONTENT_REWARD_PERCENT_HF21"] = BLURT_CONTENT_REWARD_PERCENT_HF21;
   result["BLURT_CUSTOM_OP_DATA_MAX_LENGTH"] = BLURT_CUSTOM_OP_DATA_MAX_LENGTH;
   result["BLURT_CUSTOM_OP_ID_MAX_LENGTH"] = BLURT_CUSTOM_OP_ID_MAX_LENGTH;
   result["BLURT_GENESIS_TIME"] = BLURT_GENESIS_TIME;
   result["BLURT_HARDFORK_REQUIRED_WITNESSES"] = BLURT_HARDFORK_REQUIRED_WITNESSES;
   result["BLURT_HF21_CONVERGENT_LINEAR_RECENT_CLAIMS"] = BLURT_HF21_CONVERGENT_LINEAR_RECENT_CLAIMS;
   result["BLURT_INFLATION_NARROWING_PERIOD"] = BLURT_INFLATION_NARROWING_PERIOD;
   result["BLURT_INFLATION_RATE_START_PERCENT"] = BLURT_INFLATION_RATE_START_PERCENT;
   result["BLURT_INFLATION_RATE_STOP_PERCENT"] = BLURT_INFLATION_RATE_STOP_PERCENT;
   result["BLURT_INIT_MINER_NAME"] = BLURT_INIT_MINER_NAME;
   result["BLURT_INIT_PUBLIC_KEY_STR"] = BLURT_INIT_PUBLIC_KEY_STR;
#if 0
   // do not expose private key, period.
   // we need this line present but inactivated so CI check for all constants in config.hpp doesn't complain.
   result["BLURT_INIT_PRIVATE_KEY"] = BLURT_INIT_PRIVATE_KEY;
#endif
   result["BLURT_INIT_SUPPLY"] = BLURT_INIT_SUPPLY;
   result["BLURT_IRREVERSIBLE_THRESHOLD"] = BLURT_IRREVERSIBLE_THRESHOLD;
   result["BLURT_MAX_ACCOUNT_CREATION_FEE"] = BLURT_MAX_ACCOUNT_CREATION_FEE;
   result["BLURT_MAX_ACCOUNT_NAME_LENGTH"] = BLURT_MAX_ACCOUNT_NAME_LENGTH;
   result["BLURT_MAX_ACCOUNT_WITNESS_VOTES"] = BLURT_MAX_ACCOUNT_WITNESS_VOTES;
   result["BLURT_MAX_ASSET_WHITELIST_AUTHORITIES"] = BLURT_MAX_ASSET_WHITELIST_AUTHORITIES;
   result["BLURT_MAX_AUTHORITY_MEMBERSHIP"] = BLURT_MAX_AUTHORITY_MEMBERSHIP;
   result["BLURT_MAX_BLOCK_SIZE"] = BLURT_MAX_BLOCK_SIZE;
   result["BLURT_SOFT_MAX_BLOCK_SIZE"] = BLURT_SOFT_MAX_BLOCK_SIZE;
   result["BLURT_MAX_CASHOUT_WINDOW_SECONDS"] = BLURT_MAX_CASHOUT_WINDOW_SECONDS;
   result["BLURT_MAX_COMMENT_DEPTH"] = BLURT_MAX_COMMENT_DEPTH;
   result["BLURT_MAX_INSTANCE_ID"] = BLURT_MAX_INSTANCE_ID;
   result["BLURT_MAX_MEMO_SIZE"] = BLURT_MAX_MEMO_SIZE;
   result["BLURT_MAX_WITNESSES"] = BLURT_MAX_WITNESSES;
   result["BLURT_MAX_PERMLINK_LENGTH"] = BLURT_MAX_PERMLINK_LENGTH;
   result["BLURT_MAX_PROXY_RECURSION_DEPTH"] = BLURT_MAX_PROXY_RECURSION_DEPTH;
   result["BLURT_MAX_RUNNER_WITNESSES_HF17"] = BLURT_MAX_RUNNER_WITNESSES_HF17;
   result["BLURT_MAX_SATOSHIS"] = BLURT_MAX_SATOSHIS;
   result["BLURT_MAX_SHARE_SUPPLY"] = BLURT_MAX_SHARE_SUPPLY;
   result["BLURT_MAX_SIG_CHECK_DEPTH"] = BLURT_MAX_SIG_CHECK_DEPTH;
   result["BLURT_MAX_SIG_CHECK_ACCOUNTS"] = BLURT_MAX_SIG_CHECK_ACCOUNTS;
   result["BLURT_MAX_TIME_UNTIL_EXPIRATION"] = BLURT_MAX_TIME_UNTIL_EXPIRATION;
   result["BLURT_MAX_TRANSACTION_SIZE"] = BLURT_MAX_TRANSACTION_SIZE;
   result["BLURT_MAX_UNDO_HISTORY"] = BLURT_MAX_UNDO_HISTORY;
   result["BLURT_MAX_URL_LENGTH"] = BLURT_MAX_URL_LENGTH;
   result["BLURT_MAX_VOTE_CHANGES"] = BLURT_MAX_VOTE_CHANGES;
   result["BLURT_MAX_VOTED_WITNESSES_HF17"] = BLURT_MAX_VOTED_WITNESSES_HF17;
   result["BLURT_MAX_WITHDRAW_ROUTES"] = BLURT_MAX_WITHDRAW_ROUTES;
   result["BLURT_MAX_WITNESS_URL_LENGTH"] = BLURT_MAX_WITNESS_URL_LENGTH;
   result["BLURT_MIN_ACCOUNT_CREATION_FEE"] = BLURT_MIN_ACCOUNT_CREATION_FEE;
   result["BLURT_MIN_ACCOUNT_NAME_LENGTH"] = BLURT_MIN_ACCOUNT_NAME_LENGTH;
   result["BLURT_MIN_BLOCK_SIZE_LIMIT"] = BLURT_MIN_BLOCK_SIZE_LIMIT;
   result["BLURT_MIN_BLOCK_SIZE"] = BLURT_MIN_BLOCK_SIZE;
   result["BLURT_MIN_CONTENT_REWARD"] = BLURT_MIN_CONTENT_REWARD;
   result["BLURT_MIN_CURATE_REWARD"] = BLURT_MIN_CURATE_REWARD;
   result["BLURT_MIN_PERMLINK_LENGTH"] = BLURT_MIN_PERMLINK_LENGTH;
   result["BLURT_MIN_REPLY_INTERVAL_HF20"] = BLURT_MIN_REPLY_INTERVAL_HF20;
   result["BLURT_MIN_ROOT_COMMENT_INTERVAL"] = BLURT_MIN_ROOT_COMMENT_INTERVAL;
   result["BLURT_MIN_COMMENT_EDIT_INTERVAL"] = BLURT_MIN_COMMENT_EDIT_INTERVAL;
   result["BLURT_MIN_VOTE_INTERVAL_SEC"] = BLURT_MIN_VOTE_INTERVAL_SEC;
   result["BLURT_MINER_ACCOUNT"] = BLURT_MINER_ACCOUNT;
   result["BLURT_MIN_PAYOUT"] = BLURT_MIN_PAYOUT;
   result["BLURT_MIN_PRODUCER_REWARD"] = BLURT_MIN_PRODUCER_REWARD;
   result["BLURT_MIN_TRANSACTION_EXPIRATION_LIMIT"] = BLURT_MIN_TRANSACTION_EXPIRATION_LIMIT;
   result["BLURT_MIN_TRANSACTION_SIZE_LIMIT"] = BLURT_MIN_TRANSACTION_SIZE_LIMIT;
   result["BLURT_MIN_UNDO_HISTORY"] = BLURT_MIN_UNDO_HISTORY;
   result["BLURT_NULL_ACCOUNT"] = BLURT_NULL_ACCOUNT;
   result["BLURT_OWNER_AUTH_RECOVERY_PERIOD"] = BLURT_OWNER_AUTH_RECOVERY_PERIOD;
   result["BLURT_OWNER_CHALLENGE_COOLDOWN"] = BLURT_OWNER_CHALLENGE_COOLDOWN;
   result["BLURT_OWNER_CHALLENGE_FEE"] = BLURT_OWNER_CHALLENGE_FEE;
   result["BLURT_OWNER_UPDATE_LIMIT"] = BLURT_OWNER_UPDATE_LIMIT;
   result["BLURT_POST_AVERAGE_WINDOW"] = BLURT_POST_AVERAGE_WINDOW;
   result["BLURT_POST_REWARD_FUND_NAME"] = BLURT_POST_REWARD_FUND_NAME;
   result["BLURT_POST_WEIGHT_CONSTANT"] = BLURT_POST_WEIGHT_CONSTANT;
   result["BLURT_PROXY_TO_SELF_ACCOUNT"] = BLURT_PROXY_TO_SELF_ACCOUNT;
   result["BLURT_SECONDS_PER_YEAR"] = BLURT_SECONDS_PER_YEAR;
   result["BLURT_PROPOSAL_FUND_PERCENT_HF21"] = BLURT_PROPOSAL_FUND_PERCENT_HF21;
   result["BLURT_RECENT_RSHARES_DECAY_TIME_HF19"] = BLURT_RECENT_RSHARES_DECAY_TIME_HF19;
   result["BLURT_REVERSE_AUCTION_WINDOW_SECONDS_HF21"] = BLURT_REVERSE_AUCTION_WINDOW_SECONDS_HF21;
   result["BLURT_ROOT_POST_PARENT"] = BLURT_ROOT_POST_PARENT;
   result["BLURT_SAVINGS_WITHDRAW_REQUEST_LIMIT"] = BLURT_SAVINGS_WITHDRAW_REQUEST_LIMIT;
   result["BLURT_SAVINGS_WITHDRAW_TIME"] = BLURT_SAVINGS_WITHDRAW_TIME;
   result["BLURT_SOFT_MAX_COMMENT_DEPTH"] = BLURT_SOFT_MAX_COMMENT_DEPTH;
   result["BLURT_TEMP_ACCOUNT"] = BLURT_TEMP_ACCOUNT;
   result["BLURT_UPVOTE_LOCKOUT_HF17"] = BLURT_UPVOTE_LOCKOUT_HF17;
   result["BLURT_UPVOTE_LOCKOUT_SECONDS"] = BLURT_UPVOTE_LOCKOUT_SECONDS;
   result["BLURT_VESTING_FUND_PERCENT_HF16"] = BLURT_VESTING_FUND_PERCENT_HF16;
   result["BLURT_VESTING_WITHDRAW_INTERVALS"] = BLURT_VESTING_WITHDRAW_INTERVALS;
   result["BLURT_VESTING_WITHDRAW_INTERVAL_SECONDS"] = BLURT_VESTING_WITHDRAW_INTERVAL_SECONDS;
   result["BLURT_VOTE_DUST_THRESHOLD"] = BLURT_VOTE_DUST_THRESHOLD;
   result["BLURT_VOTING_MANA_REGENERATION_SECONDS"] = BLURT_VOTING_MANA_REGENERATION_SECONDS;
   result["BLURT_SYMBOL"] = BLURT_SYMBOL;
   result["VESTS_SYMBOL"] = VESTS_SYMBOL;
   result["BLURT_VIRTUAL_SCHEDULE_LAP_LENGTH2"] = BLURT_VIRTUAL_SCHEDULE_LAP_LENGTH2;
   result["BLURT_DELEGATION_RETURN_PERIOD_HF20"] = BLURT_DELEGATION_RETURN_PERIOD_HF20;
   result["BLURT_RD_MIN_DECAY_BITS"] = BLURT_RD_MIN_DECAY_BITS;
   result["BLURT_RD_MAX_DECAY_BITS"] = BLURT_RD_MAX_DECAY_BITS;
   result["BLURT_RD_DECAY_DENOM_SHIFT"] = BLURT_RD_DECAY_DENOM_SHIFT;
   result["BLURT_RD_MAX_POOL_BITS"] = BLURT_RD_MAX_POOL_BITS;
   result["BLURT_RD_MAX_BUDGET_1"] = BLURT_RD_MAX_BUDGET_1;
   result["BLURT_RD_MAX_BUDGET_2"] = BLURT_RD_MAX_BUDGET_2;
   result["BLURT_RD_MAX_BUDGET_3"] = BLURT_RD_MAX_BUDGET_3;
   result["BLURT_RD_MAX_BUDGET"] = BLURT_RD_MAX_BUDGET;
   result["BLURT_RD_MIN_DECAY"] = BLURT_RD_MIN_DECAY;
   result["BLURT_RD_MIN_BUDGET"] = BLURT_RD_MIN_BUDGET;
   result["BLURT_RD_MAX_DECAY"] = BLURT_RD_MAX_DECAY;
   result["BLURT_ACCOUNT_SUBSIDY_PRECISION"] = BLURT_ACCOUNT_SUBSIDY_PRECISION;
   result["BLURT_WITNESS_SUBSIDY_BUDGET_PERCENT"] = BLURT_WITNESS_SUBSIDY_BUDGET_PERCENT;
   result["BLURT_WITNESS_SUBSIDY_DECAY_PERCENT"] = BLURT_WITNESS_SUBSIDY_DECAY_PERCENT;
   result["BLURT_DEFAULT_ACCOUNT_SUBSIDY_DECAY"] = BLURT_DEFAULT_ACCOUNT_SUBSIDY_DECAY;
   result["BLURT_DEFAULT_ACCOUNT_SUBSIDY_BUDGET"] = BLURT_DEFAULT_ACCOUNT_SUBSIDY_BUDGET;
   result["BLURT_DECAY_BACKSTOP_PERCENT"] = BLURT_DECAY_BACKSTOP_PERCENT;
   result["BLURT_BLOCK_GENERATION_POSTPONED_TX_LIMIT"] = BLURT_BLOCK_GENERATION_POSTPONED_TX_LIMIT;
   result["BLURT_PENDING_TRANSACTION_EXECUTION_LIMIT"] = BLURT_PENDING_TRANSACTION_EXECUTION_LIMIT;
   result["BLURT_TREASURY_ACCOUNT"] = BLURT_TREASURY_ACCOUNT;
   result["BLURT_TREASURY_FEE"] = BLURT_TREASURY_FEE;
   result["BLURT_PROPOSAL_MAINTENANCE_PERIOD"] = BLURT_PROPOSAL_MAINTENANCE_PERIOD;
   result["BLURT_PROPOSAL_MAINTENANCE_CLEANUP"] = BLURT_PROPOSAL_MAINTENANCE_CLEANUP;
   result["BLURT_PROPOSAL_SUBJECT_MAX_LENGTH"] = BLURT_PROPOSAL_SUBJECT_MAX_LENGTH;
   result["BLURT_PROPOSAL_MAX_IDS_NUMBER"] = BLURT_PROPOSAL_MAX_IDS_NUMBER;

   return result;
}

} } // blurt::protocol
