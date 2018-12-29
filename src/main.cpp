#include "AppInfo.h"
#include "Blockchain.h"

#include <iostream>

int main()
{
   std::cout << APPNAME << " " << VERSION << "\n\n";

   Blockchain blockchain;

   blockchain.addBlock(new Block{1, "10/07/2018", "{ amount: 4 }"});
   blockchain.addBlock(new Block{2, "12/07/2018", "{ amount: 10}"});

   std::cout << blockchain << "\n\n";

   std::cout << "The blockchain is "
             << (blockchain.isValid() ? "valid" : "not valid") << "\n\n";

   return 0;
}
