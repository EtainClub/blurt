#!/bin/bash

# UPDATE YOUR DEBIAN 10 SYSTEM TO THE LATEST VERSIONS OF PACKAGES
apt update
apt upgrade -y

# INSTALL Dependencies
apt install -y ntp unzip wget libbz2-dev libsnappy-dev libncurses5-dev libreadline-dev

# ENABLE NTP
systemctl enable ntp
systemctl start ntp

# CREATE BLURT USER
mkdir /blurt 
adduser --gecos "" --disabled-password --home /blurt blurt
chown blurt /blurt


# FILESYSTEM LIMITS AS ADVISED HERE: https://developers.steem.io/tutorials-recipes/exchange_node
echo "*      hard    nofile     94000" >> /etc/security/limits.conf
echo "*      soft    nofile     94000" >> /etc/security/limits.conf
echo "*      hard    nproc      64000" >> /etc/security/limits.conf
echo "*      soft    nproc      64000" >> /etc/security/limits.conf
echo "fs.file-max = 2097152" >> /etc/sysctl.conf
sysctl -p


# DOWNLOAD BUILD ARTIFACTS OF LATEST WITNESS JOB
wget -O download https://gitlab.com/blurt/blurt/-/jobs/644121113/artifacts/download


# UNZIP AND INSTALL BLURT AT /usr/bin
unzip download
mv build/programs/blurtd/blurtd /usr/bin/blurtd
mv build/programs/cli_wallet/cli_wallet /usr/bin/cli_wallet
rm -rf build
rm download
chmod +x /usr/bin/blurtd
chmod +x /usr/bin/cli_wallet

# DOWNLOAD 1.3 MILLION STEEM ACCOUNTS
wget -O /blurt/snapshot.json  https://cloudflare-ipfs.com/ipfs/QmPrwVpwe4Ya46CN9LXNnrUdWvaDLMwFetMUdpcdpjFbyu

# DOWNLOAD CONFIG.INI
wget -O /blurt/config.ini https://gitlab.com/blurt/blurt/-/raw/dev/doc/exchanges/exchange_config.ini

# INSTALL BLURTD.SERVICE 
wget -O /etc/systemd/system/blurtd.service https://gitlab.com/blurt/blurt/-/raw/dev/doc/blurtd.service

# ENABLE BLURTD SYSTEMD SERVICE
systemctl enable blurtd

# START BLURTD
systemctl start blurtd 

# LOVE USERS
echo -e "\e[1;31;42m Thank you for running Blurt infrastructure, and listing BLURT. \e[0m"
echo -e "\e[1;31;42m BLURT LOVES YOU! \e[0m"



