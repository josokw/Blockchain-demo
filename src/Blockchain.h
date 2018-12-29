#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <iostream>
#include <memory>
#include <vector>

#include "Block.h"

class Blockchain
{
   friend std::ostream &operator<<(std::ostream &os,
                                   const Blockchain &blockchain);

public:
   Blockchain();
   ~Blockchain() = default;

   void addBlock(Block *pBlock);
   bool isValid() const;

private:
   std::vector<Block *> blockchain_;

   Block *getLastBlock() { return blockchain_[blockchain_.size() - 1]; }
};

#endif
