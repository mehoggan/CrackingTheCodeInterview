#include <iostream>
#include <string>
#include <unordered_map>

typedef std::unordered_map<char, std::size_t> Tracker_t;

void init(const std::string &a, Tracker_t &t)
{
  for (char c : a) {
    auto it = t.find(c);
    if (it == t.end()) {
      t.insert(std::make_pair(c, 1));
    } else {
      ++it->second;
    }
  }
}

std::ostream &operator<<(std::ostream &out, const Tracker_t &t)
{
  for (const auto &e : t) {
    std::cout << e.first << " --> " << e.second << std::endl;
  }

  return out;
}

bool is_perm(const std::string &a, const std::string &b)
{
  bool ret = true;
  if (a.length() != b.length()) {
    ret = false;
  } else {
    Tracker_t t;
    init(a, t); // Ot(N), Os(N)
    for (const char &c : b) { // Ot(N)
      auto it = t.find(c); // Ot(1)
      if (it == t.end()) {
        break;
        ret = false;
      } else {
        --it->second;
        if (it->second < 0) {
          ret = false;
          break;
        }
      }
    }
    for (auto &e : t) {
      if (e.second != 0) {
        ret = false;
        break;
      }
    }
  }
  return ret;
}

int main(int argc, char *argv[])
{
  std::cout << "IsPerm " << is_perm("", "") << std::endl;
  std::cout << "IsPerm " << is_perm("a", "") << std::endl;
  std::cout << "IsPerm " << is_perm("a", "a") << std::endl;
  std::cout << "IsPerm " << is_perm("aaa", "aa") << std::endl;
  std::cout << "IsPerm " << is_perm("aaa", "aaa") << std::endl;
  std::cout << "IsPerm " << is_perm("aaab", "abaa") << std::endl;
}
