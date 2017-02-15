#include <iostream>
#include <vector>

#include <math.h>

#ifndef FREQ_H
#define FREQ_H

typedef struct
{
  int c;
  int n;
}pair;

class Freq
{
public:
  void print();
  void compute(std::vector<char> data);
  void add(char c);
  float entropie();
  std::vector<pair> getF();
private:
  std::vector<char> d;
  std::vector<pair> f;
};

#endif
