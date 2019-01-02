#include "Blockchain.h"

#include "ClocksTimers.h"

std::ostream &operator<<(std::ostream &os, const Blockchain &blockchain)
{
   for (auto &bl : blockchain.blockchain_) {
      os << *bl << "\n";
   }
   return os;
}

Blockchain::Blockchain(uint64_t difficulty)
   : difficulty_{difficulty}
   , blockchain_{}
{
   blockchain_.emplace_back(
      std::make_unique<Block>(0, "01/01/2018", "Genesis block", "0"));
}

void Blockchain::addBlock(uint64_t index, const std::string &data)
{
   auto pBlock = std::make_unique<Block>(index, nowAsString(), data,
                                         getLastBlock().getHash());
   pBlock->mine(difficulty_);
   blockchain_.push_back(std::move(pBlock));
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

json Blockchain::toJSON() const
{
   json jsonData;

   jsonData["length"] = blockchain_.size();
   for (auto &block : blockchain_) {
      jsonData["chain"][block->getIndex()] = block->toJSON();
   }

   return jsonData;
}
