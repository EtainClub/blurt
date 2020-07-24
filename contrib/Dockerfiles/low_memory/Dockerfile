FROM debian:10

MAINTAINER Jacob Gadikian <jacob@blurt.foundation>

# FETCH DEPENDENCIES
RUN apt update
RUN apt upgrade -y

# Install Dependencies
RUN apt install -y ntp unzip wget libbz2-dev libsnappy-dev libncurses5-dev libreadline-dev

RUN mkdir /blurt && \
            wget --progress=bar:force:noscroll -O /blurt/snapshot.json  https://cloudflare-ipfs.com/ipfs/QmPrwVpwe4Ya46CN9LXNnrUdWvaDLMwFetMUdpcdpjFbyu

# INSTALL TEST TOOLS
RUN apt install -y curl jq

# GET LATEST JOB BINARIES
RUN wget --progress=bar:force:noscroll -O download https://gitlab.com/blurt/blurt/-/jobs/artifacts/dev/download?job=low_memory && \
        unzip download && \
        mv build/bin/blurtd /usr/bin/blurtd && \
        mv build/bin/cli_wallet /usr/bin/cli_wallet && \
        chmod +x /usr/bin/blurtd && \
        chmod +x /usr/bin/cli_wallet && \
        rm -rf build && \
        rm download


# RUN BLURT
CMD ["/usr/bin/blurtd", "--data-dir /blurt"]


EXPOSE 8090
EXPOSE 8091
EXPOSE 1776