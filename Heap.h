#ifndef HEAP_H
#define HEAP_H

#include <map>
#include <vector>
#include <iostream>
#include "HuffmanNode.h"
using namespace std;
 

class HuffmanNode;


class Heap {
 public:
  Heap();
  ~Heap();
  void insertNode(HuffmanNode * node);
  void insert(char c, int p);
  void printHeap();
  HuffmanNode* findMin();
  void deleteMin();
  void percolateDown(int i);
  HuffmanNode * huffmanify();
  void codeGen(HuffmanNode * node, string n);
  map<char, string> getCodes();
  HuffmanNode * createHuffman(map<string, char> codes, string prefix, HuffmanNode * node);
  bool decode(HuffmanNode * node, string bits);
 private:

  map<char, string> codes;
  int count;
  vector<HuffmanNode*> v;
};

#endif
