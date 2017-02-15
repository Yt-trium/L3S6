#include <fstream>
#include <vector>

class IO
{
public:
  void setFilename(std::string f);
  std::vector<char> read();
  void write(std::vector<char> d);
private:
  std::string filename;
};
