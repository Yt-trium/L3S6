#include <iostream>

#include "io.h"
#include "freq.h"
#include "huffman.h"

int main(int argc, char **argv)
{
  IO *io = new IO();

  io->setFilename("a.txt");
  std::vector<char> d = io->read();

  Freq *f = new Freq();
  f->compute(d);
  // f->print();
  // std::cout << f->entropie() << std::endl;

  std::vector<pair> freq = f->getF();
  Huffman *h = new Huffman();
  h->createTree(freq);

  io->setFilename("c.txt");
  io->write(d);


  return 0;
}
