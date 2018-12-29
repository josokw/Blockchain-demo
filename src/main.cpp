#include "AppInfo.h"
#include "Blockchain.h"

#include <iostream>

int main(int argc, char *argv[])
{
   std::cout << APPNAME << " " << VERSION << "\n\n";

    uint32_t difficulty{4};

    if (argc == 2) {
       difficulty = std::stoul(argv[1]);
    }

   Blockchain blockchain{difficulty};

   blockchain.addBlock(new Block{1, "10/07/2018", "{ amount: 4 }"});
   blockchain.addBlock(new Block{2, "12/07/2018", "{ amount: 10}"});

   std::cout << "\nBlockchain:\n" << blockchain << "\n\n";

   std::cout << "The blockchain is "
             << (blockchain.isValid() ? "valid" : "not valid") << "\n\n";

   return 0;
}
