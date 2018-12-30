#include "Block.h"
#include "SHA256/sha256.h"

#include <sstream>

std::ostream &operator<<(std::ostream &os, const Block &block)
{
   os << "[" << block.index_ << "] " << block.timestamp_ << " " << block.data_
      << " " << block.previousHash_ << " " << block.hash_ << " "
      << block.nonce_;

   return os;
}

Block::Block(uint64_t index, const std::string &timestamp,
             const std::string &data, const std::string &previousHash)
   : index_{index}
   , timestamp_{timestamp}
   , data_{data}
   , previousHash_{previousHash}
   , hash_{calculateHash()}
   , nonce_{0}
{
}

std::string Block::calculateHash() const
{
   std::stringstream ss;
   ss << index_ << previousHash_ << timestamp_ << data_ << nonce_;

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

   jsData["index"] = index_;
   jsData["timestamp"] = timestamp_;
   jsData["data"] = data_;
   jsData["previousHash"] = previousHash_;
   jsData["hash"] = hash_;
   jsData["nonce"] = nonce_;

   return jsData;
}
