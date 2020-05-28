#include <blurt/plugins/follow/follow_operations.hpp>

#include <blurt/protocol/operation_util_impl.hpp>

namespace blurt { namespace plugins{ namespace follow {

void follow_operation::validate()const
{
   FC_ASSERT( follower != following, "You cannot follow yourself" );
}

void reblog_operation::validate()const
{
   FC_ASSERT( account != author, "You cannot reblog your own content" );
}

} } } //blurt::plugins::follow

BLURT_DEFINE_OPERATION_TYPE( blurt::plugins::follow::follow_plugin_operation )
