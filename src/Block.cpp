#include "Block.h"
#include "SHA256/sha256.h"

#include <sstream>

std::ostream &operator<<(std::ostream &os, const Block &block)
{
   os << "[" << block.index_ << "] " << block.timestamp_ << " "
      << block.data_ << " " << block.previousHash_ << " " << block.hash_;

   return os;
}

Block::Block(uint64_t index, const std::string &timestamp,
             const std::string &data, const std::string &previousHash)
   : index_{index}
   , timestamp_{timestamp}
   , data_{data}
   , previousHash_{previousHash}
   , hash_{calculateHash()}
{
}

std::string Block::calculateHash() const
{
   std::stringstream ss;
   ss << index_ << previousHash_ << timestamp_ << data_;

   return sha256(ss.str());
}
