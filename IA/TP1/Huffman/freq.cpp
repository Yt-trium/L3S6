#include "freq.h"

void Freq::compute(std::vector<char> data)
{
  d = data;

  char c = 0;
  f.clear();

  pair p;

  // INIT
  for(c=-128;true;c++)
  {
    p.c = 0;
    p.n = 0;
    f.push_back(p);

    // Le love du beau code <3 <3
    if(c==127)
      break;
  }

  size_t i = 0;
  while(i<d.size())
  {
    add(d.at(i));
    i++;
  }
}

void Freq::print()
{
    size_t i = 0;
    while(i<f.size())
    {
      std::cout << (int)f.at(i).c << " [" << (char)f.at(i).c
      << "] " << f.at(i).n << std::endl;
      i++;
    }
}

void Freq::add(char c)
{
  int x = c;
  if(x<0)
    x+=256;

  f[x].c = c;
  f[x].n++;
}

float Freq::entropie()
{
  float pv, e=0;
  size_t i = 0;

  while(i<f.size())
  {
    if(f.at(i).n > 0)
    {
      pv = ((float)f.at(i).n / (float)d.size());
      e += pv * (log(pv) / log(2));
    }
    i++;
  }
  e = -e;

  /*
  for(c=0;c<=65533;c++)
  {
    if(freqTable.get(c) > 0)
    {
        pv = (float)((float)freqTable.get(c) / (float)size);
        e += pv * (Math.log(pv) / Math.log(2));
    }
  }
  */

  return e;
}

std::vector<pair> Freq::getF()
{
  return f;
}
