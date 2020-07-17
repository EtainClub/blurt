# Exchange Quickstart

System Requirements: 

A dedicated server or virtual machine with a minimum of 16GB of RAM, and at least 80GB of fast **local** SSD storage.



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
