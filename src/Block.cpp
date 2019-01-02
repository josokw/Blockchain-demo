#include "Block.h"

#include "SHA256/sha256.h"

#include <sstream>

std::ostream &operator<<(std::ostream &os, const Block &block)
{
   os << block.timestamp_ << " ";
   for (auto &trans : block.transactions_) {
      os << *trans << " ";
   }
   os << block.previousHash_ << " " << block.hash_ << " " << block.nonce_;

   return os;
}

Block::Block(const std::string &timestamp, transactions_t &transactions,
             const std::string &previousHash)
   : timestamp_{timestamp}
   , transactions_{std::move(transactions)}
   , previousHash_{previousHash}
   , hash_{calculateHash()}
   , nonce_{0}
{
}

std::string Block::calculateHash() const
{
   std::stringstream ss;
   ss << previousHash_ << timestamp_ << nonce_;

   return sha256(ss.str());
}

void Block::mine(uint32_t difficulty)
{
   const std::string leading0s(difficulty, '0');

   while (hash_.substr(0, difficulty) != leading0s) {
      nonce_++;
      hash_ = calculateHash();
   }

   std::cout << "Block mined: " << hash_ << std::endl;
}

json Block::toJSON() const
{
   json jsData;

   jsData["timestamp"] = timestamp_;

   jsData["previousHash"] = previousHash_;
   jsData["hash"] = hash_;
   jsData["nonce"] = nonce_;

   return jsData;
}
