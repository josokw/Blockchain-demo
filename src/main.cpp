#include "AppInfo.h"
#include "Blockchain.h"

#include <iostream>

int main()
{
   std::cout << APPNAME << " " << VERSION << "\n\n";

   Blockchain blockchain;

   blockchain.addBlock(new Block{1, "1/1/2019", "block 1"});
   blockchain.addBlock(new Block{2, "2/1/2019", "block 2"});
   blockchain.addBlock(new Block{3, "3/1/2019", "block 3"});

   std::cout << blockchain << "\n\n";

   return 0;
}
