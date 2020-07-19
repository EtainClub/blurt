# Blurt

[![pipeline status](https://gitlab.com/blurt/blurt/badges/dev/pipeline.svg)](https://gitlab.com/blurt/blurt/-/commits/dev)
[![coverage report](https://gitlab.com/blurt/blurt/badges/dev/coverage.svg)](https://gitlab.com/blurt/blurt/-/commits/dev)
![Twitter URL](https://img.shields.io/twitter/url?style=social&url=https%3A%2F%2Ftwitter.com%2FBlurtOfficial)
[![Steem](https://img.shields.io/badge/-steem-blue)](https://steemit.com/steem/@blurt)
[![Hive](https://img.shields.io/badge/-hive-red)](https://hive.blog/@blurt)

Blurt is a public social blockchain with a diverse and vibrant community that strictly upholds [property rights](https://twitter.com/cz_binance/status/1236373815447506945?s=20).
Blurt contains balances imported from Steem Block 43,526,969.  

## Features

* No Downvotes
* [No Stablecoin](https://blurt.world/blurt/@jacobgadikian/blurt-has-no-dollar-stablecoin-why)
* Transaction fees [controlled by witnesses](https://blurt.world/blurt/@jacobgadikian/witnesses-control-fees-on-blurt)
* A **regent account** with a controlling stake or special weighted vote has been added to Blurt. 
  * The regent account votes on consensus Blurt Producers and DAO proposals.
  * The regent account is programmed to decay over a two-year period with 24 equal monthly reductions to zero, starting at a power equal to all blurt supply. 
  * **The regent account does not impact**:
    * circulating supply
    * new inflation A.K.A. organic supply
    * the rewards pool
* **Imported to Blurt From Steem**:
  * Balances - less Steemit stake described in this issue https://gitlab.com/blurt/blurt/-/issues/10
  * SBD balances were converted to BLURT at the chain-reported price of $.26/STEEM from Block 43,526,969
* **Not Imported to Blurt From Steem**:
  * Content
  * Followers
  * Profile Pic
  * Name
  * Location
  * Pending Claimed Accounts
  * Account Authorizations

## Economy

* Ticker symbol BLURT
* Staked BLURT is called BLURT POWER
* There is no stablecoin on the Blurt Blockchain. SBD balances are converted to their BLURT equivalent when the snapshot is taken.
* Blurt uses Graphene Delegated Proof-of-Stake Consensus (DPOS), and is looking into alternatives like Cosmos-SDK / Tenderrmint.
* 10% APR inflation narrowing to 1% APR over 20 years
    * 65% of inflation to Authors/Curators.
    * 15% of inflation to Stakeholders.
    * 10% of inflation to Blurt Producers.
    * 10% of inflation to Blurt DAO Fund.


## Status

Blurt launched on July 4, 2020 with bugs affecting:

**Resource Credits**
The resource credit bug allowed for unrestricted writes to the Blurt blockchain, and this was exploited by the account `@social` to post hundreds of thousands prepared 64kb comments whose sole contents was a GIF of a penis or jpg of two men deeply enjoying one another's company. 
After consulting with the community, HF1, which introduced [controlled by witnesses](https://blurt.world/blurt/@jacobgadikian/witnesses-control-fees-on-blurt) was released. 
Witnesses have currently stabilized fees at 0.001 BLURT per operation and 0.1 BLURT per kilobyte.    

**Rewards**
The convergent linear reward curve currently used by BLURT is malfunctioning.  Rewards will be fixed in [Hard Fork 2](https://gitlab.com/blurt/blurt/-/milestones/2), which will be released ~August 1, 2020. 

**Development**
Work is ongoing in the `dev` branch.  
The snapshot-verification code can be found in the `snapshot` branch.  

## Documentation

[Developers](doc/devs/README.md)
[Exchanges](doc/exchanges/README.md)
[Witnesses](doc/witnesses/README.md)
