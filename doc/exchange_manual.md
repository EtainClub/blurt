# Running an exchange node manually

This document guides you how to run an exchange node manually with clean Ubuntu 18.04 docker image.

System Requirements: 
A dedicated server or virtual machine with a minimum of 16GB of RAM, and at least 160GB of SSD storage.


#### 1. Install Docker
Assume that docker is install on your system. If not follow the guide on docker doc to install.

#### 2. Download 
This step to download:
- `snapshot.json` (genesis file)
- `blurtd` (pre-built binary)
- `config.ini` (sample config)

You could change the `BLURT_DIR` to the location to store the data

```
export BLURT_DIR=/Volumes/RAMDisk/blurtd
export BLURT_ARTIFACTS=https://gitlab.com/blurt/blurt/-/jobs/644229270/artifacts/download

cd $BLURT_DIR
mkdir -p tmp && wget -O $BLURT_DIR/tmp/download $BLURT_ARTIFACTS && unzip $BLURT_DIR/tmp/download -d $BLURT_DIR/tmp/ && mv $BLURT_DIR/tmp/build/programs/blurtd/blurtd ./ && rm -rf tmp

wget -O $BLURT_DIR/snapshot.json https://cloudflare-ipfs.com/ipfs/QmPrwVpwe4Ya46CN9LXNnrUdWvaDLMwFetMUdpcdpjFbyu
wget -O $BLURT_DIR/config.ini https://gitlab.com/blurt/blurt/-/raw/dev/doc/exchange_config.ini
chmod +x blurtd
```

#### 3. Config node

To track specific accounts instead of all accounts, add this to config.ini:

Eg., tracking `birdinc` account only

```
account-history-track-account-range = ["birdinc", "birdinc"]
```

#### 3. Run node

To run in interactive bash shell in the container, use option `-it` instead of `-d`

```
docker run --name blurtd_exchange --rm -d \
    -v $BLURT_DIR:/blurtd \
    -p 2001:2001 -p 8090:8090 -p 8091:8091 \
    --ulimit nofile=94000:94000 --ulimit nproc=64000:64000 \
    --stop-timeout 30 \
    ubuntu:18.04 \
    /bin/bash -c "
    apt-get update -qq && 
    apt-get install -qq libsnappy-dev libncurses-dev libreadline-dev && 
    ln -s /lib/x86_64-linux-gnu/libncurses.so.5.9 /lib/x86_64-linux-gnu/libncurses.so.6 && 
    ln -s /lib/x86_64-linux-gnu/libncursesw.so.5.9 /lib/x86_64-linux-gnu/libtinfo.so.6 && 
    cd /blurtd && ./blurtd -d ."
```

To monitor or view log from the container, run:
```
docker logs -f blurtd_exchange
```

To stop node, run:
```
docker stop -t 30 blurtd_exchange
```

To resynch the chain from start, delete the `blockchain` folder then start the node again.
