#include "AppInfo.h"
#include "Blockchain.h"
#include "ClocksTimers.h"

#include <iostream>

int main(int argc, char *argv[])
{
   std::cout << APPNAME_VERSION << "\n\n";

   uint32_t difficulty{4};

   if (argc == 2) {
      difficulty = std::stoul(argv[1]);
   }

   Blockchain josokwCoin{difficulty};

   josokwCoin.createTransaction("address1", "address2", 100);
   josokwCoin.createTransaction("address2", "address1", 50);

   std::cout << "Starting the miner...\n";
   josokwCoin.minePendingTransactions("josokw-address");

   std::cout << "\nBlockchain JSON:\n" << josokwCoin.toJSON().dump(3) << "\n\n";

   std::cout << "Balance 'josokw' is "
             << josokwCoin.getBalanceOfAddress("josokw-address") << "\n\n";

   std::cout << "Starting the miner again...\n";
   josokwCoin.minePendingTransactions("josokw-address");

   std::cout << "\nBlockchain JSON:\n" << josokwCoin.toJSON().dump(3) << "\n\n";

   std::cout << "Balance 'josokw' is "
             << josokwCoin.getBalanceOfAddress("josokw-address") << "\n\n";

   std::cout << "The josokwCoin blockchain is "
             << (josokwCoin.isValid() ? "valid" : "not valid") << "\n\n";

   return 0;
}
