#include "Blockchain.h"

#include "ClocksTimers.h"

std::ostream &operator<<(std::ostream &os, const Blockchain &blockchain)
{
   for (auto &bl : blockchain.blockchain_) {
      os << *bl << "\n";
   }
   return os;
}

Blockchain::Blockchain(uint64_t difficulty, int miningReward)
   : difficulty_{difficulty}
   , miningReward_{miningReward}
   , blockchain_{}
   , pendingTransactions_{}
{
   blockchain_.emplace_back(
      std::make_unique<Block>(nowAsString(), pendingTransactions_, "0"));
}

void Blockchain::createTransaction(const std::string &fromAddress,
                                   const std::string &toAddress, int amount)
{
   pendingTransactions_.push_back(
      std::move(std::make_unique<Transaction>(fromAddress, toAddress, amount)));
}

void Blockchain::minePendingTransactions(const std::string &miningRewardAddress)
{
   auto pBlock = std::make_unique<Block>(nowAsString(), pendingTransactions_,
                                         getLastBlock().getHash());
   pBlock->mine(difficulty_);
   blockchain_.emplace_back(std::move(pBlock));

   createTransaction("", miningRewardAddress, miningReward_);
}

int Blockchain::getBalanceOfAddress(const std::string &address) const
{
   int balance{0};

   for (const auto &block : blockchain_) {
      for (const auto &trans : block->getTransactions()) {
         if (trans->getFromAddress() == address) {
            balance -= trans->getAmount();
         }
         if (trans->getToAddress() == address) {
            balance += trans->getAmount();
         }
      }
   }

   return balance;
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
   u_int32_t index{0};
   for (auto &block : blockchain_) {
      jsonData["chain"][index++] = block->toJSON();
   }
   index = 0;
   for (auto &tr : pendingTransactions_) {
      jsonData["pendingTransactions"][index++] = tr->toJSON();
   }

   return jsonData;
}
