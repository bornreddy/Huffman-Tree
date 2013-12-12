#include "Heap.h"
#include "HuffmanNode.h"
#include <iostream>
#include <tr1/unordered_map>
#include <stdio.h>
#include <cstdlib>
using namespace std::tr1;


typedef std::tr1::unordered_map<char, int> Mymap; 
int main( int argc, char **argv ){
  unordered_map<char, int> freqs;
  Heap m;
  
  if ( argc != 2 ) {
    cout << "Must supply the input file name as the one and only parameter" << endl;
    exit(1);
  }
  FILE *fp = fopen(argv[1], "r");
  if ( fp == NULL ) {
    cout << "File '" << argv[1] << "' does not exist!" << endl;
    exit(2);
  }
  char g;
  while ( (g = fgetc(fp)) != EOF ) {
    if (g == '\n') continue;
    if (g == '\r') continue;
    if (freqs.count(g) == 0) {
      freqs.insert(make_pair(g,0));
    }
    freqs[g] = freqs[g]+1;
  }
  for ( Mymap::iterator it = freqs.begin(); it != freqs.end(); ++it ) {
    m.insert(it->first, it->second);
     }
   HuffmanNode * j = NULL;
   j = m.huffmanify();
   cout << "huffman created" << endl;
    m.codeGen(j,"");
    cout << "----------------------------------------" << endl;
    int oldSize = 0;
    int newSize = 0;
    rewind(fp);

    while ( (g = fgetc(fp)) != EOF ) {
      if (g == '\n') continue;        
      if (g == '\r') continue;
      oldSize++;
      newSize += m.getCodes()[g].length();
      cout <<m.getCodes()[g] << " ";
      

    }
    fclose(fp);
    cout << endl;
    cout << "----------------------------------------" << endl;
    cout << "Compression ratio is: " << (oldSize + 0.0)/(newSize + 0.0) << endl;
    int sum = 0;
    for ( Mymap::iterator it = freqs.begin(); it != freqs.end(); ++it ) {
      char h = it->first;
      int f = it->second;
      sum += m.getCodes()[h].length() * f;

    }
    float cost = (sum + 0.0)/(oldSize + 0.0);
    cout << "The Huffman tree cost per character: " << cost << endl;
      
  return 0;
}
