#!/bin/bash

echo blurtd-testnet: getting deployment scripts from external source

wget -qO- $SCRIPTURL/master/$LAUNCHENV/$APP/testnetinit.sh > /usr/local/bin/testnetinit.sh
wget -qO- $SCRIPTURL/master/$LAUNCHENV/$APP/testnet.config.ini > /etc/blurtd/testnet.config.ini
wget -qO- $SCRIPTURL/master/$LAUNCHENV/$APP/fastgen.config.ini > /etc/blurtd/fastgen.config.ini
chmod +x /usr/local/bin/testnetinit.sh

echo blurtd-testnet: launching testnetinit script

/usr/local/bin/testnetinit.sh
