#include <cstdint>
#include <iostream>
#include <unordered_map>

typedef std::unordered_map<std::size_t, std::size_t> Tracker_t;

std::size_t ways_to_go_up(std::size_t N, Tracker_t &tracker)
{
  std::size_t sum = 0;
  if (tracker.find(N) != tracker.end()) {
    return tracker.find(N)->second;
  } else if (N == 1) {
    return 1;
  } else if (N == 2) {
    return 2;
  } else if (N == 3) {
    return 4;
  } else {
    for (std::size_t s = 1; s < N; ++s) {
      std::size_t sum_bottom = ways_to_go_up(s, tracker);
      tracker.insert(std::make_pair(s, sum_bottom));
      std::size_t sum_top = ways_to_go_up(N - s, tracker);
      tracker.insert(std::make_pair(N - s, sum_top));
      sum += (sum_bottom + sum_top);
    }
  }
  return sum;
}

int main(int argc, char *argv[])
{
  std::string part_2 = "and the option to go up 1, 2, or 3 steps, ";
  std::string part_3 = "there are ";
  std::string part_4 = " ways to go up the stairs.";
  {
    std::string part_1 = "Given 1 step ";
    Tracker_t tracker;
    std::cout << part_1 << part_2 << part_3 << ways_to_go_up(1, tracker)
      << part_4 << std::endl;
  }
  {
    std::string part_1 = "Given 2 steps ";
    Tracker_t tracker;
    std::cout << part_1 << part_2 << part_3 << ways_to_go_up(2, tracker)
      << part_4 << std::endl;
  }
  {
    std::string part_1 = "Given 3 steps ";
    Tracker_t tracker;
    std::cout << part_1 << part_2 << part_3 << ways_to_go_up(3, tracker)
      << part_4 << std::endl;
  }
  {
    std::string part_1 = "Given 4 steps ";
    Tracker_t tracker;
    std::cout << part_1 << part_2 << part_3 << ways_to_go_up(4, tracker)
      << part_4 << std::endl;
  }
  {
    std::string part_1 = "Given 5 steps ";
    Tracker_t tracker;
    std::cout << part_1 << part_2 << part_3 << ways_to_go_up(5, tracker)
      << part_4 << std::endl;
  }
  {
    std::string part_1 = "Given 6 steps ";
    Tracker_t tracker;
    std::cout << part_1 << part_2 << part_3 << ways_to_go_up(6, tracker)
      << part_4 << std::endl;
  }
  return 0;
}
