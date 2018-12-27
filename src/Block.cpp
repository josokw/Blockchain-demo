#include "Block.h"
#include "SHA256/sha256.h"
#include "JSON/json.hpp"

#include <sstream>

std::ostream &operator<<(std::ostream &os, const Block &block)
{
   os << block.index_ << " " << block.timestamp_ << " " << block.data_ << " "
      << block.hash_;
   return os;
}

Block::Block(uint64_t index, const std::string &timestamp,
             const std::string &data, const std::string &previousHash)
   : index_{index}
   , timestamp_{timestamp}
   , data_{data}
   , previousHash_{previousHash}
   , hash_{}
{
   calculateHash();
}

void Block::calculateHash()
{
   std::stringstream ss;
   ss << index_ << previousHash_ << timestamp_ << data_ << '\0';
   std::cout << __func__ << " " << ss.str() << "\n\n";
   hash_ = sha256(ss.str());
}
