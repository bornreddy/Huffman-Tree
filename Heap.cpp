/*Marisa Reddy
 *mpr2zp
 *23 November 2013
 *Filename: Heap.cpp
 */
#include <algorithm>
#include<map>
#include "Heap.h"
#include "HuffmanNode.h"
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;



Heap::Heap() {
  
  for (int i=0; i<v.size(); i++) {
    v[i] = NULL;
  }
  HuffmanNode * starter = new HuffmanNode('m', 10000);
  v.push_back(starter);
  count = 0;
}

Heap::~Heap() {
  for (int i=0; i<v.size(); i++) {
    if (v[i] != NULL) {
      delete v[i];
    }
  }
}

void Heap::insertNode (HuffmanNode * node) {
  // Percolate up
  int hole = ++count;
  for( ; hole > 1 && node->p < v[hole /2]->p; 
       hole /= 2) {
    // if x < array[hole/2] move 
    // item in array[hole] “down”
    v[hole] = v[hole/2];
  }
  v[hole] = node;
}

void Heap::insert(char c, int p) {
  HuffmanNode * tmp = new HuffmanNode(c, p);
  insertNode(tmp);
}

void Heap::printHeap() {
  // cout << "heap is as follows" << endl;
  for (int i = 1; i < count+1; i++) {
    cout << v[i]->getP() << endl;
  }  
}

HuffmanNode * Heap::findMin() {
  return v[1];
}

void  Heap::deleteMin() {
  v[1] = v[count];
  count--;
  percolateDown(1);
}

void Heap::percolateDown( int hole )
{
  int child;
  HuffmanNode* tmp = v[ hole ];

  for( ; hole * 2 <= count; hole = child )
    {
      /* Find smaller child */
      child = hole * 2;
      if (child != count && v[child+1]->p<v[child]->p)
	child++;
      /* Percolate one level */
      if( tmp->p > v[child]->p )
	v[ hole ] = v[ child ];
      else
	break;
    }
  v[ hole ] = tmp;
}


HuffmanNode* Heap::huffmanify() {
 
  while (count != 1) {
    HuffmanNode * node = new HuffmanNode;
    HuffmanNode * a = findMin();
    //cout << "before loop" << endl;
    //printHeap();
    deleteMin();
    HuffmanNode * b = findMin();
    deleteMin();
    node->p = a->p + b->p;
    //cout << "a: " << a->p << endl;
    //cout << "b: " << b->p << endl;
    //cout << "sum of a and b" << node->getP() << endl;
    node->left = a;
    // cout << "node left" << node->left->getP() << endl;
    node ->right = b;
    // cout << "node right" << node->right->getP() << endl;
    insertNode(node);
    // cout << "after loop" << endl;
    // printHeap();
  }
  return findMin();
}
  
void Heap::codeGen(HuffmanNode * node, string n) {
  if (node->left==NULL && node->right==NULL) {
    codes.insert(make_pair(node->getC(), n));
    cout << node->getC() << " " << n << endl;
  }
  if (node->left != NULL) {
    // cout << "going left" << endl;
    codeGen(node->left, n+"0");
  }
  if (node->right != NULL) {
    //cout << "going right" << endl;
    codeGen(node->right, n+"1");
  }
}

map<char, string> Heap::getCodes() {
  return codes;
}


HuffmanNode * Heap::createHuffman(map<string, char> codes, string prefix, HuffmanNode * node) {
  if (codes.count(prefix)) {
    //  cout << "prefix found: " << prefix << endl;
    node->c = codes[prefix];
    return node;
  }
  else {
    HuffmanNode * l = new HuffmanNode;
    node->left = l;
    createHuffman(codes, prefix+"0", l);
    HuffmanNode * r = new HuffmanNode;
    node->right = r;
    createHuffman(codes, prefix+"1", r);
  } 
  return node; 
}

bool Heap::decode(HuffmanNode * node, string bits) {
  for (int i=0; i<bits.length(); i++) {
    if (bits[i] == '0') {
      node = node->left;
      if ( node->c != '\n' ) {
	cout << node->c;;
	return true;
      }
    }
    if (bits[i]== '1') {
      node = node->right;
      if ( node->c != '\n' ) {
	cout <<node->c;
	return true;
      } 
    }
  }
  return false; 
} 
