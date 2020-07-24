FROM debian:10

MAINTAINER Jacob Gadikian <jacob@blurt.foundation>

EXPOSE 8090
EXPOSE 8091
EXPOSE 1776

ARG STEEM_STATIC_BUILD=ON
ENV STEEM_STATIC_BUILD ${STEEM_STATIC_BUILD}
ARG BUILD_STEP
ENV BUILD_STEP ${BUILD_STEP}
ARG CI_BUILD
ENV CI_BUILD ${CI_BUILD}


# FETCH DEPENDENCIES
RUN apt update
RUN apt upgrade -y

# Install Dependencies
RUN apt install -y ntp unzip wget libbz2-dev libsnappy-dev libncurses5-dev libreadline-dev

# INSTALL TEST TOOLS
RUN apt install -y curl jq