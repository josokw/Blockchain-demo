#ifndef BLOCK_H
#define BLOCK_H

#include "Transaction.h"
#include "json.hpp"

#include <cstdint>
#include <iostream>
#include <memory>
#include <string>

using json = nlohmann::json;

/// Block represents a block in a blockchain.
///
/// Contains a nonce (number only used once): a number added to a block,
/// when rehashed meets the difficulty level restrictions.
class Block
{
   friend std::ostream &operator<<(std::ostream &os, const Block &block);

public:
   using transactions_t = std::vector<std::unique_ptr<Transaction>>;

   explicit Block(const std::string &timestamp, transactions_t &transactions,
                  const std::string &previousHash = "");
   Block(const Block &other) = delete;
   Block &operator=(const Block &other) = delete;
   ~Block() = default;

   const auto &getTransactions() const { return transactions_; }

   void setHash(const std::string &hash) { hash_ = hash; }
   const std::string &getHash() const { return hash_; }

   void setPreviousHash(const std::string &previousHash)
   {
      previousHash_ = previousHash;
   }
   const std::string &getPreviousHash() const { return previousHash_; }

   std::string calculateHash() const;
   void mine(uint32_t difficulty);
   json toJSON() const;

private:
   std::string timestamp_;
   transactions_t transactions_;
   std::string previousHash_;
   std::string hash_;
   uint64_t nonce_;
};

#endif
