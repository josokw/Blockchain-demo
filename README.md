# Blockchain-demo 'josokwCoin'

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/3f8150da8d7a40d69e7797a7547a4c51)](https://www.codacy.com/app/josokw/Blockchain-demo?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=josokw/Blockchain-demo&amp;utm_campaign=Badge_Grade)

This code example shows how I try to learn to write a C++ Blockchain demo version for educational purposes.
I use a 'learning by cloning' approach: refactoring JavaScript code examples to C++.

JavaScript code examples [Savjee](https://www.savjee.be/):

+ [Creating a blockchain with Javascript (Blockchain, part 1)](https://www.youtube.com/watch?v=zVqczFZr124), C++ release v0.1
+ [Implementing Proof-of-Work in Javascript (Blockchain, part 2)](https://www.youtube.com/watch?v=HneatE69814), C++ release v0.2
+ [Miner rewards & transactions in Javascript (Blockchain, part 3)](https://www.youtube.com/watch?v=fRV6cGXVQ4I), C++ release v0.3
+ [Signing transactions in Javascript (Blockchain, part 4)](https://www.youtube.com/watch?v=kWQ84S13-hw)

## Build management by CMake

CMake must be installed. Goto the Blockchain-demo directory.

    mkdir build
    cd build
    cmake ..
    make

## SHA-256

**SHA**: Secure Hash Algorithm. **SHA-256** is part of SHA-2 set of cryptographic hash functions, designed by the U.S. National Security Agency (NSA) and published in 2001. The **SHA-2** family consists of six hash functions with digests (hash values) that are 224, 256, 384 or 512 bits: SHA-224, SHA-256, SHA-384, SHA-512, SHA-512/224, SHA-512/256.

Some examples hashing strings:

```
"1"      ==> 6b86b273ff34fce19d6b804eff5a3f5747ada4eaa22f1d49c01e52ddb7875b4b
"12"     ==> 6b51d431df5d7f141cbececcf79edf3dd861c3b4069f0b11661a3eefacbba918
"123"    ==> a665a45920422f9d417e4867efdc4fb8a04a1f3fff1fa07e998e86f7f7a27ae3
"321"    ==> 8d23cf6c86e834a7aa6eded54c26ce2bb2e74903538c61bdd5d2197997ab2f72
"abc321" ==> 95d0bf701b3efa5fe1207167d08044bac7ae34c090af18847c915c5c8a49455a
"     "  ==> 399141be1d30ac2656d89eedcf0d8dcedaa72d6c29bf959cae243dc7b1442cf6
"abc"    ==> ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad
```
[Online hash generator](https://passwordsgenerator.net/sha256-hash-generator/).

[How secure is 256 bit security?](https://www.youtube.com/watch?v=S9JGmA5_unY)

## Executing 'Blockchain-demo' and mining

The executable is found in the bin directory. The default difficulty level for mining is 4.

    cd ../bin
    ./Blockchain-demo

**Proof of work** (POW): a method to insure that the new block was difficult (costly, time consuming) to be made. The hash of a block must start with a certain number of zeros. 

The **nonce** in a bitcoin block is a 32-bit (4-byte) field whose value is set so that the hash of the block will contain a run of leading zeros. 

The difficulty level for mining can be changed by a command line parameter.

    cd ../bin
    ./Blockchain-demo 3

## Bitcoin: critique and problems ==> IOTA

- [Huge amount of powerconsumption for mining](https://www.theguardian.com/technology/2017/nov/27/bitcoin-mining-consumes-electricity-ireland).

- [Scalability problem](https://hackernoon.com/the-blockchain-scalability-problem-the-race-for-visa-like-transaction-speed-5cce48f9d44).

- The [IOTA Tangle](http://tangle.glumb.de/) takes another approach: [no blocks, no chain (Directed Acyclic Graph)](https://www.iota.org/research/meet-the-tangle). 

## Output example

Output in JSON format for difficulty level 4:

    BlockchainDemo v0.3.0

    Starting the miner...
    Block mined: 0000bb9a29f319d928ee4a1644ede1ca77969bad2368a5380bbc25e05669dc44

    Blockchain JSON:
    {
    "chain": [
        {
            "hash": "a18993cf60a314d0c460c8b014ffe3d67fe2bcf4b09d4f5cea14e5259991b703",
            "nonce": 0,
            "previousHash": "0",
            "timestamp": "2019/01/04-10.26.54"
        },
        {
            "hash": "0000bb9a29f319d928ee4a1644ede1ca77969bad2368a5380bbc25e05669dc44",
            "nonce": 1464,
            "previousHash": "a18993cf60a314d0c460c8b014ffe3d67fe2bcf4b09d4f5cea14e5259991b703",
            "timestamp": "2019/01/04-10.26.54",
            "transactions": [
                {
                "amount": 100,
                "fromAddress": "address1",
                "timestamp": "2019/01/04-10.26.54",
                "toAddress": "address2"
                },
                {
                "amount": 50,
                "fromAddress": "address2",
                "timestamp": "2019/01/04-10.26.54",
                "toAddress": "address1"
                }
            ]
        }
    ],
    "length": 2,
    "pendingTransactions": [
        {
            "amount": 100,
            "fromAddress": "",
            "timestamp": "2019/01/04-10.26.54",
            "toAddress": "josokw-address"
        }
    ]
    }

    Balance 'josokw' is 0

    Starting the miner again...
    Block mined: 00001623918c0e568ea6fd5d0717bb9ecc0eef0ad9b185fe218141c72fd294c5

    Blockchain JSON:
    {
    "chain": [
        {
            "hash": "a18993cf60a314d0c460c8b014ffe3d67fe2bcf4b09d4f5cea14e5259991b703",
            "nonce": 0,
            "previousHash": "0",
            "timestamp": "2019/01/04-10.26.54"
        },
        {
            "hash": "0000bb9a29f319d928ee4a1644ede1ca77969bad2368a5380bbc25e05669dc44",
            "nonce": 1464,
            "previousHash": "a18993cf60a314d0c460c8b014ffe3d67fe2bcf4b09d4f5cea14e5259991b703",
            "timestamp": "2019/01/04-10.26.54",
            "transactions": [
                {
                "amount": 100,
                "fromAddress": "address1",
                "timestamp": "2019/01/04-10.26.54",
                "toAddress": "address2"
                },
                {
                "amount": 50,
                "fromAddress": "address2",
                "timestamp": "2019/01/04-10.26.54",
                "toAddress": "address1"
                }
            ]
        },
        {
            "hash": "00001623918c0e568ea6fd5d0717bb9ecc0eef0ad9b185fe218141c72fd294c5",
            "nonce": 41362,
            "previousHash": "0000bb9a29f319d928ee4a1644ede1ca77969bad2368a5380bbc25e05669dc44",
            "timestamp": "2019/01/04-10.26.54",
            "transactions": [
                {
                "amount": 100,
                "fromAddress": "",
                "timestamp": "2019/01/04-10.26.54",
                "toAddress": "josokw-address"
                }
            ]
        }
    ],
    "length": 3,
    "pendingTransactions": [
        {
            "amount": 100,
            "fromAddress": "",
            "timestamp": "2019/01/04-10.26.54",
            "toAddress": "josokw-address"
        }
    ]
    }

    Balance 'josokw' is 100

    The josokwCoin blockchain is valid
