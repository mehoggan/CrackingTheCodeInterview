#include <iostream>
#include <unordered_set>

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

Node *remove_dups(Node *head)
{
  if (head != nullptr) {
    std::unordered_set<char> uniques;
    Node *curr = head, *prev = head;
    while (curr != nullptr) {
      auto it = uniques.find(curr->c_);
      if (it == uniques.end()) {
        uniques.insert(curr->c_);
        prev = curr;
        curr = curr->next_;
      } else {
        prev->next_ = curr->next_;
        curr->next_ = nullptr;
        delete curr;
        curr = prev->next_;
      }
    }
  }
  return head;
}

int main(int argc, char *argv[])
{
  Node *head = nullptr;
  head = insert(head, 'a');
  head = insert(head, 'b');
  head = insert(head, 'a');
  head = insert(head, 'c');
  head = insert(head, 'b');
  head = insert(head, 'a');
  head = insert(head, 'd');
  std::cout << head << std::endl;
  head = remove_dups(head);
  std::cout << head << std::endl;
  destroy(head);
}
