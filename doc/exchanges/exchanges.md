# Exchange Quickstart

System Requirements: 

A dedicated server or virtual machine with a minimum of 16GB of RAM, and at least 160GB of SSD storage.


### Set up a Blurt Full Node

We've reduced setting up a full node to a single-line installer.  Run the following command as root on your fresh Debian 10 physical or virtual machine.  

```bash
bash <(curl -s https://gitlab.com/blurt/blurt/-/raw/dev/doc/exchanges/exchange.bash)
```

Now you've just got to wait a bit for your machine to import 1.3 million steem accounts and sync the Blurt Blockchain.  To monitor this process, do like:

```bash
journalctl -u blurtd -f
```


### Account history and limitations

If you need to track all account history instead of just a single account, this would add quite a bit of overhead and lead to a much longer reindex. If you absolutely need this, we recommend instead using the `account_history_rocksdb` plugin instead, however, there is one caveat: the rocksdb plugin does not allow the ability to query by transaction ID. For either `account_history` or `account_history_rocksdb` you would also add the `account_history_api` plugin in order to be able to query data. To use these, you would add them to a custom config file.


To track specific accounts add this to /blurt/config.ini:
```
account-history-track-account-range = ["nameofaccount", "nameofaccount"]
```




### Running the cli_wallet

The cli_wallet is installed at /usr/bin/cli_wallet.  

You can run it by simply invoking `cli_wallet` from the user and filesystem location of your choice.  Wallet.json will be stored there.  


### Upgrading for major releases that require a full reindex

For upgrades that require a full replay, we highly recommend *performing the upgrade on a separate server* in order to minimize downtime of your wallet. When the replay is complete, switch to the server running the newer version of Blurt. 
