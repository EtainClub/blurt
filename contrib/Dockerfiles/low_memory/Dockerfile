MAINTAINER Jacob Gadikian <jacob@blurt.foundation>

FROM debian:10

EXPOSE 8090
EXPOSE 8091
EXPOSE 1776

# FETCH DEPENDENCIES
RUN apt update
RUN apt upgrade -y

# Install Dependencies
RUN apt install -y ntp unzip wget libbz2-dev libsnappy-dev libncurses5-dev libreadline-dev

# INSTALL TEST TOOLS
RUN apt install -y curl jq

# GET LATEST JOB BINARIES
RUN mkdir /blurtd && \
    wget --progress=bar:force:noscroll -O /blurtd/snapshot.json  https://cloudflare-ipfs.com/ipfs/QmPrwVpwe4Ya46CN9LXNnrUdWvaDLMwFetMUdpcdpjFbyu

# RUN BLURT
CMD /usr/bin/blurtd --data-dir /blurtd

