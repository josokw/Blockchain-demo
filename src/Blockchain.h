#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "Block.h"
#include "Transaction.h"
#include "JSON/json.hpp"

#include <iostream>
#include <memory>
#include <vector>

using json = nlohmann::json;

/// The class Blockchain represents a blockchain implemented in an STL vector
/// containing unique_ptr's to Block objects.
/// All Blocks are owned by Blockchain.
class Blockchain
{
   friend std::ostream &operator<<(std::ostream &os,
                                   const Blockchain &blockchain);

public:
   explicit Blockchain(uint64_t difficulty = 3, int miningReward = 100);
   ~Blockchain() = default;

   void createTransaction(const std::string &fromAddress,
                          const std::string &toAddress, int amount);
   void minePendingTransaction(const std::string &miningRewardAddress);
   int getBalanceOfAddress(const std::string &address) const;
   bool isValid() const;
   json toJSON() const;

private:
   using blockchain_t = std::vector<std::unique_ptr<Block>>;
   using pendingtransactions_t = std::vector<std::unique_ptr<Transaction>>;

   uint64_t difficulty_;
   int miningReward_;
   blockchain_t blockchain_;
   pendingtransactions_t pendingTransactions_;

   Block &getLastBlock() { return *(blockchain_[blockchain_.size() - 1]); }
};

#endif
