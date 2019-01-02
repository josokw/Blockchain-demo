#include "AppInfo.h"
#include "Blockchain.h"
#include "ClocksTimers.h"

#include <iostream>

int main(int argc, char *argv[])
{
   std::cout << APPNAME << " " << VERSION << "\n\n";

   uint32_t difficulty{4};

   if (argc == 2) {
      difficulty = std::stoul(argv[1]);
   }

   Blockchain josokwCoin{difficulty};

   josokwCoin.createTransaction("a", "b", 111);
   josokwCoin.createTransaction("c", "d", 222);
   josokwCoin.createTransaction("e", "f", 333);
   josokwCoin.createTransaction("g", "h", 444);

   josokwCoin.minePendingTransaction("thisIsMe");

   std::cout << "\nBlockchain JSON:\n" << josokwCoin.toJSON().dump(3) << "\n\n";
   std::cout << "Balance 'a' is " << josokwCoin.getBalanceOfAddress("a")
             << "\n\n";

   josokwCoin.createTransaction("b", "a", 1111);
   josokwCoin.minePendingTransaction("thisIsMe");

   std::cout << "\nBlockchain JSON:\n" << josokwCoin.toJSON().dump(3) << "\n\n";

   std::cout << "Balance 'thisIsMe' is "
             << josokwCoin.getBalanceOfAddress("thisIsMe") << "\n\n";

   std::cout << "The josokwCoin blockchain is "
             << (josokwCoin.isValid() ? "valid" : "not valid") << "\n\n";

   return 0;
}
