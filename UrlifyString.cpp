#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>

struct Words
{
  std::vector<std::string> words;

  explicit Words(const std::string str)
  {
    std::stringstream ss(str);
    std::istream_iterator<std::string> begin(ss);
    std::istream_iterator<std::string> end;
    words = std::vector<std::string>(begin, end);
  }
};

std::ostream &operator<<(std::ostream &out, const Words& words)
{
  for (const std::string &word : words.words) {
    std::cout << word << " ";
  }
  return out;
}

typedef char* StringBuffer_t;

void url_ify(StringBuffer_t url)
{
  Words words(url);
  std::size_t count = words.words.size();
  std::cout << words << std::endl;
  std::cout << "Running algorithm." << std::endl;
  std::size_t index = 0;
  std::size_t word_i = 0;
  for (const auto &word : words.words) {
    for (char c : word) {
      url[index] = c;
      ++index;
    }
    ++word_i;
    if (word_i != count - 1) {
      url[index++] = '%';
      url[index++] = '2';
      url[index++] = '0';
    }
  }
  std::cout << url << std::endl;
}

int main(int argc, char *argv[])
{
  char buffer[] = {
    'T', 'h', 'i', 's',
    ' ', 'i', 's',
    ' ', 'a',
    ' ', 'u', 'r', 'l', '.',
    '\0', '\0', '\0', '\0', '\0', '\0', '\0' };
  url_ify(buffer);
  return 0;
}
