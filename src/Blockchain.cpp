#include "Blockchain.h"

std::ostream &operator<<(std::ostream &os, const Blockchain &blockchain)
{
   for (auto bl : blockchain.blockchain_) {
      os << *bl << "\n";
   }
   return os;
}

Blockchain::Blockchain()
   : blockchain_{}
{
   blockchain_.emplace_back(
      new Block(0, std::string("1/1/2019"), "Genesis block", "0"));
}

void Blockchain::addBlock(Block *pBlock)
{
   pBlock->setPreviousHash(getLastBlock()->getHash());
   pBlock->calculateHash();
   blockchain_.push_back(pBlock);
}
