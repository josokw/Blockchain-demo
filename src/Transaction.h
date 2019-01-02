#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <string>

class Transaction
{
   friend std::ostream &operator<<(std::ostream &os,
                                   const Transaction &transaction);

public:
   Transaction(const std::string &fromAddress, const std::string &toAddress,
               int amount);
   ~Transaction() = default;

   const auto &getFromAddress() const { return fromAddress_; }
   const auto &getToAddress() const { return toAddress_; }
   auto getAmount() const { return amount_; } 

private:
   std::string fromAddress_;
   std::string toAddress_;
   int amount_;
};

#endif
