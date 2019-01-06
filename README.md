# Blockchain-demo

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/3f8150da8d7a40d69e7797a7547a4c51)](https://www.codacy.com/app/josokw/Blockchain-demo?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=josokw/Blockchain-demo&amp;utm_campaign=Badge_Grade)

This code example shows how I try to learn to write a C++ Blockchain demo version for educational purposes.
I use a 'learning by cloning' approach: refactoring JavaScript code examples to C++.

JavaScript code examples [Savjee](https://www.savjee.be/):

+ [Creating a blockchain with Javascript (Blockchain, part 1)](https://www.youtube.com/watch?v=zVqczFZr124), release v0.1
+ [Implementing Proof-of-Work in Javascript (Blockchain, part 2)](https://www.youtube.com/watch?v=HneatE69814), release v0.2
+ [Miner rewards & transactions in Javascript (Blockchain, part 3)](https://www.youtube.com/watch?v=fRV6cGXVQ4I), release v0.3
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

Output for difficulty level 4:

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
