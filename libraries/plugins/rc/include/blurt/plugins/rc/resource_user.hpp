#pragma once

#include <blurt/protocol/types.hpp>

#include <fc/reflect/reflect.hpp>

namespace blurt { namespace protocol {
struct signed_transaction;
} } // blurt::protocol

namespace blurt { namespace plugins { namespace rc {

using blurt::protocol::account_name_type;
using blurt::protocol::signed_transaction;

account_name_type get_resource_user( const signed_transaction& tx );

} } } // blurt::plugins::rc
