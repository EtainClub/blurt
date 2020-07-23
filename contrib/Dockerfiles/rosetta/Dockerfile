# This is a Rosetta-flavored dockerfile that complies with all Rosetta [recommendations}(https://www.rosetta-api.org/docs/node_deployment.html#dockerfile-expectations) for Dockerfiles
# * Build Anywhere
# * Compile exclusively from source
MAINTAINER Jacob Gadikian <jacob@blurt.foundation>

FROM debian:10

EXPOSE 8090
EXPOSE 8091
EXPOSE 1776

# FETCH DEPENDENCIES
RUN apt-get update && \
    apt-get install -y -qq autoconf automake cmake g++ git libtool make pkg-config python3 python3-jinja2 doxygen perl wget clang llvm

RUN wget https://dl.bintray.com/conan/installers/conan-ubuntu-64_1_27_1.deb && \
    apt install -y ./conan-ubuntu-64_1_27_1.deb

# INSTALL TEST TOOLS
RUN apt install -y curl jq


# CLONE BLURT AND GET SUBMODULES, BUILD AS RPC NODE
RUN git clone --recursive https://gitlab.com/blurt/blurt && \
          cd blurt && \
          git checkout dev && \
          mkdir build && \
          cd build && \
          conan install .. -s compiler=gcc -s compiler.libcxx=libstdc++11 -if=. -pr=default --build=missing && \
          cmake -DBLURT_STATIC_BUILD=ON -DLOW_MEMORY_NODE=OFF -DCLEAR_VOTES=OFF -DBUILD_BLURT_TESTNET=OFF -DSKIP_BY_TX_ID=OFF -DBLURT_LINT_LEVEL=OFF -DENABLE_MIRA=OFF -DCMAKE_BUILD_TYPE=Release .. && \
          make -j$(nproc) blurtd cli_wallet && \
          mkdir /blurtd


RUN wget -O /blurtd/snapshot.json  https://cloudflare-ipfs.com/ipfs/QmPrwVpwe4Ya46CN9LXNnrUdWvaDLMwFetMUdpcdpjFbyu 1>/dev/null


# RUN BLURT
CMD /blurt/build/bin/blurtd --data-dir /blurtd


