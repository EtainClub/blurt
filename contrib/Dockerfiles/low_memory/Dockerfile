FROM debian:10

# FETCH DEPENDENCIES
RUN apt update
RUN apt upgrade -y

# Install Dependencies
RUN apt install -y ntp unzip wget libbz2-dev libsnappy-dev libncurses5-dev libreadline-dev


# GET LATEST JOB BINARIES
RUN mkdir /blurtd && \
    wget --progress=bar:force:noscroll -O /blurt/snapshot.json  https://cloudflare-ipfs.com/ipfs/QmPrwVpwe4Ya46CN9LXNnrUdWvaDLMwFetMUdpcdpjFbyu

# RUN BLURT
CMD /usr/bin/blurtd --data-dir /blurt

