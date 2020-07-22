# This is a Rosetta-flavored dockerfile that complies with all Rosetta [recommendations}(https://www.rosetta-api.org/docs/node_deployment.html#dockerfile-expectations) for Dockerfiles
# * Build Anywhere
# * Compile exclusively from source

FROM debian:10

# FETCH DEPENDENCIES
RUN apt-get update ; \
    apt-get install -y -qq autoconf automake cmake g++ git libbz2-dev libsnappy-dev libssl-dev libtool make pkg-config python3 python3-jinja2 doxygen libboost-chrono-dev libboost-context-dev libboost-coroutine-dev libboost-date-time-dev libboost-filesystem-dev libboost-iostreams-dev libboost-locale-dev libboost-program-options-dev libboost-serialization-dev libboost-signals-dev libboost-system-dev libboost-test-dev libboost-thread-dev libncurses5-dev libreadline-dev perl wget

# CLONE BLURT AND GET SUBMODULES
RUN git clone https://gitlab.com/blurt/blurt ; \
          cd blurt ; \
          git submodule update --init --recursive ; \
          git checkout dev ; \
          mkdir build ; \
          cd build ; \
          cmake -DBLURT_STATIC_BUILD=ON -DLOW_MEMORY_NODE=OFF -DCLEAR_VOTES=ON -DBUILD_BLURT_TESTNET=OFF -DSKIP_BY_TX_ID=ON -DBLURT_LINT_LEVEL=OFF -DENABLE_MIRA=OFF -DCMAKE_BUILD_TYPE=Release .. ; \
          make -j$(nproc) blurtd cli_wallet ; \
          mkdir /blurtd


RUN wget -O /blurtd/snapshot.json  https://cloudflare-ipfs.com/ipfs/QmPrwVpwe4Ya46CN9LXNnrUdWvaDLMwFetMUdpcdpjFbyu 1>/dev/null


# RUN BLURT
CMD blurt/build/programs/blurtd/blurtd --data-dir /blurtd
