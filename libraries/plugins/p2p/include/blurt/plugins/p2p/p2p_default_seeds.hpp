#pragma once

#include <vector>

namespace blurt { namespace plugins { namespace p2p {

#ifdef IS_TEST_NET
const std::vector< std::string > default_seeds;
#else
const std::vector< std::string > default_seeds = {

};
#endif

} } } // blurt::plugins::p2p
