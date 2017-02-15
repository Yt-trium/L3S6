#include "io.h"

void IO::setFilename(std::string f)
{
  filename = f;
}

std::vector<char> IO::read()
{
  std::vector<char> d;
  d.clear();

  std::ifstream file(filename);

  if(!file.is_open())
  {
    return d;
  }

  if (!file.eof() && !file.fail())
  {
    file.seekg(0, std::ios_base::end);
    std::streampos fileSize = file.tellg();
    d.resize(fileSize);

    file.seekg(0, std::ios_base::beg);
    file.read(&d[0], fileSize);
  }

  return d;
}

void IO::write(std::vector<char> d)
{
  std::ofstream file(filename);

  size_t i = 0;
  while(i<d.size())
  {
    file.put(d.at(i));
    i++;
  }
}
