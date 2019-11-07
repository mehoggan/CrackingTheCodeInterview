#include <cstdlib>
#include <iostream>
#include <stack>

std::ostream &operator<<(std::ostream &out, std::stack<char> stack)
{
  while (!stack.empty()) {
    out << stack.top();
    if (stack.size() > 1) {
      out << ", ";
    }
    stack.pop();
  }
  return out;
}

std::stack<char> sort(std::stack<char> stack)
{
  if (stack.size() > 1) {
    char top = stack.top();
    stack.pop();
    stack = sort(stack);
    std::stack<char> tmp;
    while (not stack.empty() && stack.top() < top) {
      char n = stack.top();
      stack.pop();
      tmp.push(n);
    }
    stack.push(top);
    while (not tmp.empty()) {
      char n = tmp.top();
      tmp.pop();
      stack.push(n);
    }
    std::cout << "stack = " << stack << std::endl;
  }

  return stack;
}

bool is_sorted(std::stack<char> stack)
{
  bool ret = true;
  while (not stack.empty()) {
    char n = stack.top();
    stack.pop();
    if (not stack.empty()) {
      if (n > stack.top()) {
        ret = false;
        break;
      }
    }
  }
  return ret;
}

void print_is_sorted(const std::stack<char> &stack)
{
  std::cout << "is sorted = " << (is_sorted(stack) ? "true" : "false")
    << std::endl;
}

int main(int argc, char *argv[])
{
  std::stack<char> stack;
  stack.push('y');
  stack.push('w');
  stack.push('x');
  stack.push('u');
  stack.push('z');
  print_is_sorted(stack);
  stack = sort(stack);
  print_is_sorted(stack);
  return 0;
}
