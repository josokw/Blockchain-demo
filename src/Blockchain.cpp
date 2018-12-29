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
   blockchain_.emplace_back(new Block(0, "01/01/2018", "Genesis block", "0"));
}

void Blockchain::addBlock(Block *pBlock)
{
   pBlock->setPreviousHash(getLastBlock()->getHash());
   pBlock->setHash(pBlock->calculateHash());
   blockchain_.push_back(pBlock);
}

bool Blockchain::isValid() const
{
   for (uint64_t index = 1; index < blockchain_.size(); ++index) {
      if (blockchain_[index]->getHash() !=
          blockchain_[index]->calculateHash()) {
         return false;
      }
      if (blockchain_[index]->getPreviousHash() !=
          blockchain_[index - 1]->getHash()) {
         return false;
      }
   }
   return true;
}
