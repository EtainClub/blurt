#!/bin/bash

echo /tmp/core | tee /proc/sys/kernel/core_pattern
ulimit -c unlimited

# if we're not using PaaS mode then start blurtd traditionally with sv to control it
if [[ ! "$USE_PAAS" ]]; then
  mkdir -p /etc/service/blurtd
  cp /usr/local/bin/steem-sv-run.sh /etc/service/blurtd/run
  chmod +x /etc/service/blurtd/run
  runsv /etc/service/blurtd
elif [[ "$IS_TESTNET" ]]; then
  /usr/local/bin/pulltestnetscripts.sh
else
  /usr/local/bin/startpaasblurtd.sh
fi
