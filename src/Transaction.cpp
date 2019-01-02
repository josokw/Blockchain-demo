#include "Transaction.h"

std::ostream& operator<<(std::ostream& os, const Transaction& transaction)
{
   os << transaction.fromAddress_ << " " << transaction.toAddress_ << " " 
      << transaction.amount_;

   return os;
}

Transaction::Transaction(const std::string &fromAddress,
                         const std::string &toAddress, int amount)
   : fromAddress_{fromAddress}
   , toAddress_{toAddress}
   , amount_{amount}
{
}