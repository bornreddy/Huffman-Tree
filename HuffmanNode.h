#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

class HuffmanNode {
 public:
  HuffmanNode(); 
  HuffmanNode( char character, int priority );
  ~HuffmanNode();
  int getP();
  char getC();
  void setP(int m);
  void setC(char l);
  HuffmanNode* getLeft();
  HuffmanNode* getRight();
  void setLeft(HuffmanNode* left);
  void setRight(HuffmanNode* right);
 private:
  int p;
  char c;
  HuffmanNode * left;
  HuffmanNode * right;
  HuffmanNode * parent;
  friend class Heap;
};

#endif
