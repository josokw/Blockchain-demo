#include "Transaction.h"

#include "ClocksTimers.h"
#include "sha256.h"

#include <sstream>

std::ostream &operator<<(std::ostream &os, const Transaction &transaction)
{
   os << transaction.fromAddress_ << " " << transaction.toAddress_ << " "
      << transaction.amount_ << " " << transaction.timestamp_;

   return os;
}

Transaction::Transaction(const std::string &fromAddress,
                         const std::string &toAddress, int amount)
   : fromAddress_{fromAddress}
   , toAddress_{toAddress}
   , amount_{amount}
   , timestamp_{nowAsString()}
{
}

std::string Transaction::calculateHash() const
{
   std::stringstream ss;
   ss << fromAddress_ << toAddress_ << amount_ << timestamp_;

   return sha256(ss.str());
}

json Transaction::toJSON() const
{
   json jsData;

   jsData["fromAddress"] = fromAddress_;
   jsData["toAddress"] = toAddress_;
   jsData["amount"] = amount_;
   jsData["timestamp"] = timestamp_;

   return jsData;
}