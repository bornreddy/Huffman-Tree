#include "HuffmanNode.h"
#include <iostream>

using namespace std;

int main() {
  HuffmanNode h('a',  20);
  cout << h.getP() << endl;
  cout << h.getC() << endl;
  
  return 0;
}
