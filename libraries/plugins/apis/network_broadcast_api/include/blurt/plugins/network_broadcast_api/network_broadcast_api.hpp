#pragma once
#include <blurt/protocol/block.hpp>

#include <blurt/plugins/p2p/p2p_plugin.hpp>
#include <blurt/plugins/chain/chain_plugin.hpp>
#include <blurt/plugins/json_rpc/utility.hpp>

#include <fc/optional.hpp>
#include <fc/variant.hpp>
#include <fc/vector.hpp>

#include <boost/thread/mutex.hpp>

namespace blurt { namespace plugins { namespace network_broadcast_api {

using std::vector;
using fc::variant;
using fc::optional;
using blurt::plugins::json_rpc::void_type;

using blurt::protocol::signed_transaction;
using blurt::protocol::transaction_id_type;
using blurt::protocol::signed_block;

struct broadcast_transaction_args
{
   signed_transaction   trx;
   int32_t              max_block_age = -1;
};

typedef void_type broadcast_transaction_return;

struct broadcast_block_args
{
   signed_block   block;
};

typedef void_type broadcast_block_return;

namespace detail{ class network_broadcast_api_impl; }

class network_broadcast_api
{
   public:
      network_broadcast_api();
      ~network_broadcast_api();

      DECLARE_API(
         (broadcast_transaction)
         (broadcast_block)
      )

   private:
      std::unique_ptr< detail::network_broadcast_api_impl > my;
};

} } } // blurt::plugins::network_broadcast_api

FC_REFLECT( blurt::plugins::network_broadcast_api::broadcast_transaction_args,
   (trx)(max_block_age) )

FC_REFLECT( blurt::plugins::network_broadcast_api::broadcast_block_args,
   (block) )
