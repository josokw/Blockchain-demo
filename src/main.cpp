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

   josokwCoin.addBlock(1, "{ amount: 4 }");
   josokwCoin.addBlock(2, "{ amount: 10}");

   std::cout << "\nBlockchain:\n" << josokwCoin << "\n";

   std::cout << "Blockchain JSON:\n" << josokwCoin.toJSON().dump(3) << "\n\n";

   std::cout << "The josokwCoin blockchain is "
             << (josokwCoin.isValid() ? "valid" : "not valid") << "\n\n";

   return 0;
}
