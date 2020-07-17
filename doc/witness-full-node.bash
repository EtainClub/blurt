#!/bin/bash

# UPDATE YOUR DEBIAN 10 SYSTEM TO THE LATEST VERSIONS OF PACKAGES
apt update
apt upgrade -y

# Install Dependencies
apt install -y ntp unzip wget libbz2-dev libsnappy-dev libncurses5-dev libreadline-dev

# Enable NTP
systemctl enable ntp
systemctl start ntp

# CREATE BLURT USER
mkdir /blurt 
adduser --gecos "" --disabled-password --home /blurt blur
chown blurt /blurt


# FILESYSTEM LIMITS AS ADVISED HERE: https://developers.steem.io/tutorials-recipes/exchange_node
echo "*      hard    nofile     94000" >> /etc/security/limits.conf
echo "*      soft    nofile     94000" >> /etc/security/limits.conf
echo "*      hard    nproc      64000" >> /etc/security/limits.conf
echo "*      soft    nproc      64000" >> /etc/security/limits.conf
echo "fs.file-max = 2097152" >> /etc/sysctl.conf
sysctl -p

# INSTALL IPFS SYSTEMD SERVICE
# Sample IPFS URL FROM CLOUDFLARE: https://cloudflare-ipfs.com/ipfs/QmXnnyufdzAWL5CqZ2RnSNgPbvCc1ALT73s6epPrRnZ1Xy
wget -O /etc/systemd/system/ipfs-hardened.service https://cloudflare-ipfs.com/ipfs/QmNQPATMBjfuLTmkScWAsogcPLPtPcR2goadb6tRPgEsaW


# DOWNLOAD BUILD ARTIFACTS OF LATEST WITNESS JOB
wget -O download https://gitlab.com/blurt/blurt/-/jobs/artifacts/dev/download?job=witness


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

# IMPORT 1.3 MILLION STEEM ACCOUNTS AND CONFIGURATION TEMPLATE
# testnet snaphsot.json is QmU2zT7W2GbifQxqpU9ALMNFUT2QwsBt4L7SaHpm6QTm4Q
# mainnet snapshot.json is QmPrwVpwe4Ya46CN9LXNnrUdWvaDLMwFetMUdpcdpjFbyu
wget -O /blurt/snapshot.json  https://cloudflare-ipfs.com/ipfs/QmPrwVpwe4Ya46CN9LXNnrUdWvaDLMwFetMUdpcdpjFbyu

# ipfs pin add QmU2zT7W2GbifQxqpU9ALMNFUT2QwsBt4L7SaHpm6QTm4Q
# wget -O /blurt/snapshot.json https://test.blurt.world/_download/snapshot.json

# testnet witness_config.ini is QmX5n6nVhbEKUMvgJre74wNdP7Jcq4GJRdw7G9BZF3zxnU
# mainnet witness_config.ini is QmeDJjv1hrjfnLJD2RU7BBrdMJmqgJbjJrMosc8nHfVBEh
wget -O /blurt/config.ini https://cloudflare-ipfs.com/ipfs/QmeDJjv1hrjfnLJD2RU7BBrdMJmqgJbjJrMosc8nHfVBEh


# INSTALL BLURTD.SERVICE 
# QmVeeCuWM6tdWxML7yEFfpaqZN9f4TL1WMd7wGgkp35Npz
# wget -O /etc/systemd/system/blurtd.service https://gitlab.com/blurt/blurt/-/raw/dev/doc/blurtd.service
wget -O /etc/systemd/system/blurtd.service https://cloudflare-ipfs.com/ipfs/QmVeeCuWM6tdWxML7yEFfpaqZN9f4TL1WMd7wGgkp35Npz

# ENABLE BLURTD SYSTEMD SERVICE
systemctl enable blurtd

# START BLURTD
systemctl start blurtd 

# CANNOT CURRENTLY START THIS SERVICE, IT WILL FAIL BECAUSE OF IPFS DAEMON
# systemctl start ipfs-hardened.serrvice

# LOVE USERS
echo -e "\e[1;31;42m Thank you for running Blurt infrastructure. \e[0m"
echo -e "\e[1;31;42m BLURT LOVES YOU! \e[0m"


