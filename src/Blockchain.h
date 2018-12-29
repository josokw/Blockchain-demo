#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <iostream>
#include <memory>
#include <vector>

#include "Block.h"

/// The class Blockchain represents a blockchain implemented in an STL vector.
class Blockchain
{
   friend std::ostream &operator<<(std::ostream &os,
                                   const Blockchain &blockchain);

public:
   Blockchain(uint64_t difficulty = 3);
   ~Blockchain() = default;

   void addBlock(Block *pBlock);
   bool isValid() const;

private:
   uint64_t difficulty_;
   std::vector<Block *> blockchain_;

   Block *getLastBlock() { return blockchain_[blockchain_.size() - 1]; }
};

#endif
