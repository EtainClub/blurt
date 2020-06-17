#!/bin/bash

# UPDATE YOUR DEBIAN 10 SYSTEM TO THE LATEST VERSIONS OF PACKAGES
apt update
apt upgrade -y

# INSTALL UNZIP AND WGET
apt install -y unzip wget libbz2-dev libsnappy-dev libncurses5-dev libreadline-dev

# DOWNLOAD BUILD ARTIFACTS
wget https://gitlab.com/blurt/blurt/-/jobs/596005137/artifacts/download

# UNZIP THE BUILD ARTIFACTS, BLURTD AND CLI_WALLET
unzip download

# PUT BLURTD AND CLI_WALLET ON YOUR $PATH
mv build/programs/blurtd/blurtd_witness /usr/bin/blurtd
mv build/programs/cli_wallet/cli_wallet /usr/bin/cli_wallet
rm -rf build
rm download

# ENSURE THAT BLURTD AND CLI_WALLET ARE EXECUTABLE
chmod +x /usr/bin/blurtd
chmod +x /usr/bin/cli_wallet

# MAKE ~/.blurtd AND FILL IT WITH 1.3 MILLION STEEM ACCOUNTS
mkdir /blurtd
wget -O /blurtd/snapshot.json https://test.blurt.world/_download/snapshot.json
wget -O /blurtd/config.ini https://gitlab.com/blurt/blurt/-/raw/dev/doc/witness_config.ini

# INSTALL BLURTD.SERVICE 
wget -O /etc/systemd/system/blurtd.service https://gitlab.com/blurt/blurt/-/raw/dev/doc/blurtd.service

# ENABLE BLURTD SYSTEMD SERVICE
systemctl enable blurtd

# START BLURTD
systemctl start blurtd 

# TODO: run as another user, security, system settings

