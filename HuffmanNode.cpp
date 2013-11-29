/*Marisa Reddy
 *mpr2zp
 *23 Novemeber 2013
 *Filename: HuffmanNode.cpp
 */

#include "HuffmanNode.h"
#include <iostream>

using namespace std;

HuffmanNode::HuffmanNode() {
  p = 0;
  c = '\n';
  left = NULL;
  right = NULL;
  parent = NULL;
}

HuffmanNode * HuffmanNode::getLeft() {
  return left;
}

void HuffmanNode::setLeft(HuffmanNode * l) {
  left = l;
}

void HuffmanNode::setRight(HuffmanNode * r) {
  right = r;
}

HuffmanNode * HuffmanNode::getRight() {
  return right;
}

HuffmanNode::HuffmanNode( char character, int priority ){
  p = priority;
  c = character;
  left = NULL;
  right = NULL;
  parent = NULL;
}

HuffmanNode::~HuffmanNode() {
  p = 0;
  left = NULL;
  right = NULL;
  parent = NULL;
}

char HuffmanNode::getC(){
  return c;
}

int HuffmanNode::getP(){
  return p;
}

void HuffmanNode::setP(int m) {
  p = m;
}
void HuffmanNode::setC(char l) {
  c = l;
}
