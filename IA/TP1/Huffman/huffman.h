#include "freq.h"
#include "btree.h"

#ifndef HUFFMAN_H
#define HUFFMAN_H

class Huffman
{
public:
  void createTree(std::vector<pair> f);
private:
  BTree bt;
};

#endif
