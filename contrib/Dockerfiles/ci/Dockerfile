# Blurt CI Dockerfile
# Blurt Docker images now happen quickly, and from a single Dockerfile without messy variables and such.
# If you'd like messy variables, check out the Rosetta Dockerfile!

FROM ubuntu:20.04

MAINTAINER Jacob Gadikian <jacob@blurt.foundation>


COPY build/bin/blurtd /usr/bin/blurtd
COPY build/bin/cli_wallet /usr/bin/cli_wallet

# FETCH DEPENDENCIES
RUN apt update
RUN apt upgrade -y
RUN apt install -y ntp unzip wget

RUN mkdir /blurt && \
            wget --progress=bar:force:noscroll -O /blurt/snapshot.json  https://cloudflare-ipfs.com/ipfs/QmPrwVpwe4Ya46CN9LXNnrUdWvaDLMwFetMUdpcdpjFbyu


# RUN BLURT
CMD ["/usr/bin/blurtd", "--data-dir", "/blurt"]


EXPOSE 8090
EXPOSE 8091
EXPOSE 1776