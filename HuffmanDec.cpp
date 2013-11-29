/*Mairsa Reddy
 *mpr2zp
 *11/27/13
 *Filename: HuffmanDec.cpp
 */

#include "Heap.h"
#include "HuffmanNode.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <map>
#include <stdlib.h>
using namespace std;


int main (int argc, char **argv) {
  map<string, char> codes;
  Heap m;
  
  if ( argc != 2 ) {
    cout << "Must supply the input file name as the only parameter" << endl;
    exit(1);
  }
  ifstream file(argv[1], ifstream::binary);
  if ( !file.is_open() ) {
    cout << "Unable to open file '" << argv[1] << "'." << endl;
    exit(2);
  }
  char buffer[256];
  while ( true ) {
    // read in first character on line
    char first = file.get();
    // catch DOS and UNIX newlines
    if ( (first == '\n') || (first == '\r') )
      continue;
    // read in second character on line
    char second = file.get();
    // did we encounter the separator?
    if ( (first == '-') && (second == '-') ) {
      // read in the rest of the line
      file.getline(buffer, 255, '\n');
      break;
    }
    // read in the prefix code
    file.getline(buffer, 255, '\n');
    codes.insert(make_pair(buffer, first));
    // cout << "character '" << first << "' has prefix code '" 
    // << buffer << "'" << endl;
  }
  //create tree
  HuffmanNode * root = new HuffmanNode;
  HuffmanNode * tree = NULL;
 
  tree = m.createHuffman(codes, "" ,root);
 

  // read in the second section of the file: the encoded message
  char bit;
  string bits = "";
  while ( (bit = file.get()) != '-' ) {
    if ( (bit != '0') && (bit != '1') )
      continue;
    bits += bit;
    if (m.decode(tree, bits)) {
	bits="";
      }
    // cout << "read in bit '" << bit << "'" << endl;
  }
  cout << endl;
 
  file.close();
}
