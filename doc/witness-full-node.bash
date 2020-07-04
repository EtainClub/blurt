#!/bin/bash
# TODO: run as another user, security, system settings
# POST-LAUNCH TODO: This should probably not be reading files directly from git, or if so, from versioned releases. 

# UPDATE YOUR DEBIAN 10 SYSTEM TO THE LATEST VERSIONS OF PACKAGES
apt update
apt upgrade -y

# CREATE BLURT USER
useradd -m -d /blurt blurt
useradd -m -d /ipfs ipfs

# INSTALL UNZIP AND WGET
apt install -y unzip wget libbz2-dev libsnappy-dev libncurses5-dev libreadline-dev

# FILESYSTEM LIMITS AS ADVISED HERE: https://developers.steem.io/tutorials-recipes/exchange_node
echo "*      hard    nofile     94000" >> /etc/security/limits.conf
echo "*      soft    nofile     94000" >> /etc/security/limits.conf
echo "*      hard    nproc      64000" >> /etc/security/limits.conf
echo "*      soft    nproc      64000" >> /etc/security/limits.conf
echo "fs.file-max = 2097152" >> /etc/sysctl.conf
sysctl -p

# INSTALL IPFS
wget https://dist.ipfs.io/go-ipfs/v0.6.0/go-ipfs_v0.6.0_linux-amd64.tar.gz
tar -xvzf go-ipfs_v0.6.0_linux-amd64.tar.gz
cd go-ipfs
sudo bash install.sh
cd ..
rm -rf go-ipfs

#INITALIZAE IPFS (NOTE: DO WE HAVE TO DO THIS AS THE IPFS USER ALSO?)
ipfs init
nohup ipfs daemon &
sleep 10

# INSTALL IPFS SYSTEMD SERVICE
ipfs get -o /etc/systemd/system/ipfs-hardened.service QmNQPATMBjfuLTmkScWAsogcPLPtPcR2goadb6tRPgEsaW


# DOWNLOAD BUILD ARTIFACTS
# POST-LAUNCH TODO: THIS SHOULD GET SOME KIND OF "LATEST" VERSION.  
# POST-LAUNCH TODO: CI SYSTEM SHOULD RELEASE BLURTD AND CLI_WALLET TO IPFS
# QmT6B3h88jYkEfsJCxwQQzrW1VVoido26mwJDHuiLHrciH is the build artifacts
ipfs get -o download QmT6B3h88jYkEfsJCxwQQzrW1VVoido26mwJDHuiLHrciH
# wget https://gitlab.com/blurt/blurt/-/jobs/596005137/artifacts/download

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
ipfs get -o /blurt/snapshot.json QmU2zT7W2GbifQxqpU9ALMNFUT2QwsBt4L7SaHpm6QTm4Q
ipfs pin add QmU2zT7W2GbifQxqpU9ALMNFUT2QwsBt4L7SaHpm6QTm4Q
# wget -O /blurt/snapshot.json https://test.blurt.world/_download/snapshot.json

# witness_config.ini is QmX5n6nVhbEKUMvgJre74wNdP7Jcq4GJRdw7G9BZF3zxnU
ipfs get -o /blurt/config.ini QmX5n6nVhbEKUMvgJre74wNdP7Jcq4GJRdw7G9BZF3zxnU
ipfs pin add QmX5n6nVhbEKUMvgJre74wNdP7Jcq4GJRdw7G9BZF3zxnU
# wget -O /blurt/config.ini https://gitlab.com/blurt/blurt/-/raw/dev/doc/witness_config.ini

# INSTALL BLURTD.SERVICE 
# QmVeeCuWM6tdWxML7yEFfpaqZN9f4TL1WMd7wGgkp35Npz
# wget -O /etc/systemd/system/blurtd.service https://gitlab.com/blurt/blurt/-/raw/dev/doc/blurtd.service
ipfs get -o /etc/systemd/system/blurtd.service QmVeeCuWM6tdWxML7yEFfpaqZN9f4TL1WMd7wGgkp35Npz
ipfs pin add QmVeeCuWM6tdWxML7yEFfpaqZN9f4TL1WMd7wGgkp35Npz

# ENABLE BLURTD SYSTEMD SERVICE
systemctl enable blurtd

# START BLURTD
systemctl start blurtd 

# ENABLE IPFS SYSTEMD SERVICE
systemctl enable ipfs-hardened.service

# CANNOT CURRENTLY START THIS SERVICE, IT WILL FAIL BECAUSE OF IPFS DAEMON
# systemctl start ipfs-hardened.serrvice
