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

   Blockchain blockchain{difficulty};

   blockchain.addBlock(1, nowAsString(), "{ amount: 4 }");
   blockchain.addBlock(2, nowAsString(), "{ amount: 10}");

   std::cout << "\nBlockchain:\n" << blockchain << "\n";

   std::cout << "Blockchain JSON:\n" << blockchain.toJSON().dump(3) << "\n\n";

   std::cout << "The blockchain is "
             << (blockchain.isValid() ? "valid" : "not valid") << "\n\n";

   return 0;
}
