/*Marisa Reddy
 *mpr2zp
 *23 November 2013
 *Filename: HuffmanNode.h
 */

#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

class HuffmanNode {
 public:
  HuffmanNode(); //default constructor
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
