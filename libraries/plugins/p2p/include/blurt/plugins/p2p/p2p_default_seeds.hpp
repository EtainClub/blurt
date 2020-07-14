#pragma once

#include <vector>

namespace blurt { namespace plugins { namespace p2p {

#ifdef IS_TEST_NET
const std::vector< std::string > default_seeds;
#else
const std::vector< std::string > default_seeds = {
   "seed1.blurt.world:2001",
   "seed2.blurt.world:2001",
   "blurtseed-se.privex.io:2015"
};
#endif

} } } // blurt::plugins::p2p
