#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "Block.h"
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
   Blockchain(uint64_t difficulty = 3);
   ~Blockchain() = default;

   void addBlock(uint64_t index, const std::string &data);
   bool isValid() const;
   json toJSON() const;

private:
   uint64_t difficulty_;
   std::vector<std::unique_ptr<Block>> blockchain_;

   Block &getLastBlock() { return *(blockchain_[blockchain_.size() - 1]); }
};

#endif
