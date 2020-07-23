FROM debian:10

# FETCH DEPENDENCIES
RUN apt update
RUN apt upgrade -y

# Install Dependencies
RUN apt install -y ntp unzip wget libbz2-dev libsnappy-dev libncurses5-dev libreadline-dev



# GET LATEST JOB BINARIES
RUN wget --progress=bar:force:noscroll -O download https://gitlab.com/blurt/blurt/-/jobs/artifacts/dev/download?job=rpc && \
    unzip download && \
    mv build/programs/blurtd/blurtd /usr/bin/blurtd && \
    mv build/programs/cli_wallet/cli_wallet /usr/bin/cli_wallet && \
    chmod +x /usr/bin/blurtd && \
    chmod +x /usr/bin/cli_wallet && \
    rm -rf build && \
    rm download && \
    mkdir /blurt && \
    wget --progress=bar:force:noscroll -O /blurt/snapshot.json  https://cloudflare-ipfs.com/ipfs/QmPrwVpwe4Ya46CN9LXNnrUdWvaDLMwFetMUdpcdpjFbyu

# RUN BLURT
CMD /usr/bin/blurtd --data-dir /blurt

