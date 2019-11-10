#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <unordered_set>

std::unordered_set<int> intersection(
  const std::set<int> &a,
  const std::set<int> &b)
{
  std::unordered_set<int> ret;
  std::unordered_set<int> found_in_a;

  for (int i_a : a) {
    found_in_a.insert(i_a);
  }

  for (int i_b : b) {
    if (found_in_a.find(i_b) != found_in_a.end()) {
      ret.insert(i_b);
    }
  }

  return std::move(ret);
}

int main(int argc, char *argv[])
{
  std::set<int> a = { 5, 7, 1, 6 };
  std::set<int> b = { 2, 3, 1, 5, 9, 7};
  std::unordered_set<int> inter = intersection(a, b);
  std::copy(inter.begin(), inter.end(),
    std::ostream_iterator<int>(std::cout, ", "));
  std::cout << std::endl;

  return 0;
}
