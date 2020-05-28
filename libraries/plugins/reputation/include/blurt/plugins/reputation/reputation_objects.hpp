#pragma once
#include <blurt/chain/steem_object_types.hpp>

namespace blurt { namespace chain {
struct by_account;
} }

namespace blurt { namespace plugins { namespace reputation {

using namespace std;
using namespace blurt::chain;

using chainbase::t_vector;

#ifndef BLURT_REPUTATION_SPACE_ID
#define BLURT_REPUTATION_SPACE_ID 17
#endif

enum reputation_plugin_object_type
{
   reputation_object_type        = ( BLURT_REPUTATION_SPACE_ID << 8 )
};


class reputation_object : public object< reputation_object_type, reputation_object >
{
   public:
      template< typename Constructor, typename Allocator >
      reputation_object( Constructor&& c, allocator< Allocator > a )
      {
         c( *this );
      }

      reputation_object() {}

      id_type           id;

      account_name_type account;
      share_type        reputation;
};

typedef oid< reputation_object > reputation_id_type;

typedef multi_index_container<
   reputation_object,
   indexed_by<
      ordered_unique< tag< by_id >, member< reputation_object, reputation_id_type, &reputation_object::id > >,
      ordered_unique< tag< by_account >, member< reputation_object, account_name_type, &reputation_object::account > >
   >,
   allocator< reputation_object >
> reputation_index;

} } } // blurt::plugins::reputation


FC_REFLECT( blurt::plugins::reputation::reputation_object, (id)(account)(reputation) )
CHAINBASE_SET_INDEX_TYPE( blurt::plugins::reputation::reputation_object, blurt::plugins::reputation::reputation_index )
