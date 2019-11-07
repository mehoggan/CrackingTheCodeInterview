#include <string>
#include <iostream>

struct CharOccur
{
  unsigned char key;
  std::size_t count;
};

typedef CharOccur Tracker_t[256];

void init(Tracker_t &t)
{
  for (std::size_t i = 0; i < 256; ++i) {
    t[i] = {static_cast<unsigned char>(i), 0};
  }
}

std::ostream &operator<<(std::ostream& out, const Tracker_t& t)
{
  out.flush();
  for (std::size_t i = 0; i < 256; ++i) {
    out << t[i].key << "-->" << t[i].count;
    if (i != 255) {
      out << std::endl;
    }
  }
  return out;
}

bool is_unique(const std::string &str)
{
  std::cout << "Looking at \"" << str << "\"" << std::endl;
  Tracker_t tracker;
  init(tracker);
  for (const unsigned char& c : str) {
    std::size_t index = static_cast<std::size_t>(c);
    tracker[index].count++;
    if (tracker[index].count > 1) {
      return false;
    }
  }
  return true;
}

int main(int argc, char *argv[])
{
  std::cout << is_unique("a cat") << std::endl;
  std::cout << is_unique("a dog") << std::endl;
  std::cout << is_unique("a dog is") << std::endl;
}
