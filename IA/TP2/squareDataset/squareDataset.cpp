#include <iostream>
#include <fstream>

double square(double x)
{
  return x*x;
}

void squareDataset(std::string filename)
{
  std::string line;

  std::ofstream out(filename);

  double x;
  double fx;
  /*
  for(x=-0.1;x<0.101;x+=0.001)
  {
    fx = square(x);
    line.clear();
    line = std::to_string(x) + ',' + std::to_string(fx) + '\n';
    out << line;
  }
  */

  for(x=-100;x<100.001;x+=0.1)
  {
    fx = square(x);
    line.clear();
    line = std::to_string(x/10000) + ',' + std::to_string(fx/10000) + '\n';
    out << line;
  }
  
  /*
  for(x=-100;x<101;x+=1)
  {
    fx = square(x);
    line.clear();
    line = std::to_string(x) + ',' + std::to_string(fx) + '\n';
    out << line;
  }

  for(x=-10000;x<10001;x+=100)
  {
    fx = square(x);
    line.clear();
    line = std::to_string(x) + ',' + std::to_string(fx) + '\n';
    out << line;
  }
  */
  out.close();
}

int main(int argc, char **argv)
{
  squareDataset("dataset_SQUARE.csv");
  return 0;
}
