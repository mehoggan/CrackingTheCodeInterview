#include <iostream>
#include <stack>

struct Node
{
  Node(char c) :
    c_(c)
  {}

  char c_;
  Node *next_;
};

Node *insert(Node *head, char c)
{
  if (head == nullptr) {
    head = new Node(c);
  } else {
    Node *curr = head;
    while (curr->next_ != nullptr) {
      curr = curr->next_;
    }
    curr->next_ = new Node(c);
  }

  return head;
}

Node *destroy(Node *head)
{
  if (head == nullptr) {
    return head;
  } else {
    Node *prev = head;
    Node *curr = head;
    while (curr != nullptr) {
      prev = curr;
      curr = curr->next_;
      delete prev;
    }
  }
}

std::size_t length(Node* head)
{
  std::size_t len = 0;
  Node *curr = head;
  while(curr != nullptr) {
    len += 1;
    curr = curr->next_;
  }
  return len;
}

std::ostream &operator<<(std::ostream &out, const Node& curr)
{
  out << curr.c_;
  return out;
}

std::ostream &operator<<(std::ostream &out, Node *head)
{
  Node *curr = head;
  while (curr != nullptr) {
    out << (*curr) << " --> ";
    curr = curr->next_;
    out.flush();
  }
  out << "nullptr";
  return out;
}

bool is_palindrome(Node *head)
{
  bool ret = true;
  std::size_t len = length(head);

  if (len >= 2) {
    std::size_t mid = len / 2;
    std::size_t i = 0;
    std::stack<char> stack;
    Node *curr = head;
    while (curr != nullptr) {
      if (i < mid) {
        std::cout << "Pushing " << curr->c_ << std::endl;
        stack.push(curr->c_);
      } else if (len % 2 == 1 && i == mid) {
        std::cout << "Not pushing " << curr->c_ << std::endl;
      } else {
        char c = curr->c_;
        char n = stack.top();
        std::cout << "Checking next = " << c << " against stack = "
          << n << std::endl;
        if (c != n) {
          ret = false;
          break;
        }
        stack.pop();
      }

      ++i;
      curr = curr->next_;
    }
  }

  return ret;
}

int main(int argc, char *argv[])
{
  Node *head = nullptr;
  head = insert(head, 'm');
  head = insert(head, 'a');
  head = insert(head, 'd');
  head = insert(head, 'd');
  head = insert(head, 'a');
  head = insert(head, 'c');
  std::cout << head << std::endl;
  bool is_pali = is_palindrome(head);
  std::cout << (is_pali ? "true" : "false") << std::endl;
  destroy(head);
}
