#ifndef BLOCK_H
#define BLOCK_H

#include <cstdint>
#include <string>
#include <iostream>

class Block
{
   friend std::ostream& operator<<(std::ostream &os, const Block &block);

public:
   Block(uint64_t index, const std::string &timestamp, const std::string &data,
         const std::string &previousHash = "");
   Block(const Block &other) = delete;
   Block &operator=(const Block &other) = delete;
   ~Block() = default;

   const std::string &getHash() const { return hash_; }
   void setPreviousHash(const std::string &previousHash)
   {
      previousHash_ = previousHash;
   }
   void calculateHash();

private:
   uint64_t index_;
   std::string timestamp_;
   std::string data_;
   std::string previousHash_;
   std::string hash_;
};

#endif
