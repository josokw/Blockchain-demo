# Blockchain-demo

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/3f8150da8d7a40d69e7797a7547a4c51)](https://www.codacy.com/app/josokw/Blockchain-demo?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=josokw/Blockchain-demo&amp;utm_campaign=Badge_Grade)

This code example shows how I try to learn to write a C++ Blockchain demo version for educational purposes.

The C++ code is based on Javascript code:

+ [Creating a blockchain with Javascript (Blockchain, part 1)](https://www.youtube.com/watch?v=zVqczFZr124).
+ [Implementing Proof-of-Work in Javascript (Blockchain, part 2)](https://www.youtube.com/watch?v=HneatE69814)

## Build management by CMake

CMake must be installed. Goto the Blockchain-demo directory.

    mkdir build
    cd build
    cmake ..
    make

## Executing 'Blockchain-demo'

The executable is found in the bin directory. The default difficulty level for mining is 3.

    cd ../bin
    ./Blockchain-demo

The difficulty level for mining can be changed by a command line parameter.

    cd ../bin
    ./Blockchain-demo 4
