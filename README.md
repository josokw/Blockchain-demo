# Blockchain-demo

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/3f8150da8d7a40d69e7797a7547a4c51)](https://www.codacy.com/app/josokw/Blockchain-demo?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=josokw/Blockchain-demo&amp;utm_campaign=Badge_Grade)

This code example shows how I try to learn to write a C++ Blockchain demo version for educational purposes.

The C++ code is based on Javascript code:

 + [Creating a blockchain with Javascript (Blockchain, part 1)](https://www.youtube.com/watch?v=zVqczFZr124), release v0.1
 + [Implementing Proof-of-Work in Javascript (Blockchain, part 2)](https://www.youtube.com/watch?v=HneatE69814), release v0.2
 + [Miner rewards & transactions in Javascript (Blockchain, part 3)](https://www.youtube.com/watch?v=fRV6cGXVQ4I)
 + [Signing transactions in Javascript (Blockchain, part 4)](https://www.youtube.com/watch?v=kWQ84S13-hw)

## Build management by CMake

CMake must be installed. Goto the Blockchain-demo directory.

    mkdir build
    cd build
    cmake ..
    make

## Executing 'Blockchain-demo'

The executable is found in the bin directory. The default difficulty level for mining is 4.

    cd ../bin
    ./Blockchain-demo

The difficulty level for mining can be changed by a command line parameter.

    cd ../bin
    ./Blockchain-demo 3

## Output example

Output for difficulty level 3:

    BlockchainDemo 0.1.2

    Block mined: 000385a6d97b8d566f574911fcd6e1805a8d3fb880de2d3a5c9b8f7c4dc8dfb2
    Block mined: 000b5b2895e90d463c9c401eb29cf611257162c851fdb4f9fdefb9ca79337773

    Blockchain:
    [0] 01/01/2018 Genesis block 0 6a26925d3118f38f7bea9e9bbaf7edc7fc0ee67c64385325a16957809256e27f 0
    [1] 10/07/2018 { amount: 4 } 6a26925d3118f38f7bea9e9bbaf7edc7fc0ee67c64385325a16957809256e27f 000385a6d97b8d566f574911fcd6e1805a8d3fb880de2d3a5c9b8f7c4dc8dfb2 13434
    [2] 12/07/2018 { amount: 10} 000385a6d97b8d566f574911fcd6e1805a8d3fb880de2d3a5c9b8f7c4dc8dfb2 000b5b2895e90d463c9c401eb29cf611257162c851fdb4f9fdefb9ca79337773 4642


    Blockchain JSON:
    {
    "chain": [
        {
            "data": "Genesis block",
            "hash": "6a26925d3118f38f7bea9e9bbaf7edc7fc0ee67c64385325a16957809256e27f",
            "index": 0,
            "nonce": 0,
            "previousHash": "0",
            "timestamp": "01/01/2018"
        },
        {
            "data": "{ amount: 4 }",
            "hash": "000385a6d97b8d566f574911fcd6e1805a8d3fb880de2d3a5c9b8f7c4dc8dfb2",
            "index": 1,
            "nonce": 13434,
            "previousHash": "6a26925d3118f38f7bea9e9bbaf7edc7fc0ee67c64385325a16957809256e27f",
            "timestamp": "10/07/2018"
        },
        {
            "data": "{ amount: 10}",
            "hash": "000b5b2895e90d463c9c401eb29cf611257162c851fdb4f9fdefb9ca79337773",
            "index": 2,
            "nonce": 4642,
            "previousHash": "000385a6d97b8d566f574911fcd6e1805a8d3fb880de2d3a5c9b8f7c4dc8dfb2",
            "timestamp": "12/07/2018"
        }
    ],
    "length": 3
    }

    The blockchain is valid
