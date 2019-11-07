#include <iostream>
#include <queue>
#include <stdexcept>

struct TreeNode
{
  TreeNode(int val) :
    val(val),
    left(nullptr),
    right(nullptr)
  {}

  int val;
  TreeNode *left;
  TreeNode *right;
};

std::ostream &operator<<(std::ostream &out, const TreeNode &n)
{
  out << n.val;
  return out;
}

void print_tree(std::ostream &out, TreeNode *root)
{
  if (root == nullptr) {
    return;
  } else {
    out << (*root);

    if (root->left != nullptr) {
      out << " (left) ";
    }
    print_tree(out, root->left);

    if (root->right != nullptr) {
      out << " (right) ";
    }
    print_tree(out, root->right);
  }
}

enum class Dir
{
  LEFT,
  RIGHT
};

std::ostream &operator<<(std::ostream &out, std::queue<Dir> dirs)
{
  while (not dirs.empty()) {
    Dir dir = dirs.front();
    dirs.pop();
    if (dir == Dir::LEFT) {
      out << "Left";
    } else {
      out << "Right";
    }
  }
  return out;
}

TreeNode* insert(int val, TreeNode *root, std::queue<Dir> &dirs)
{
  if (dirs.empty() && root != nullptr) {
    throw std::runtime_error("Not enough directions");
  } else if (not dirs.empty() && root == nullptr) {
    throw std::runtime_error("To many direction.");
  } else if (dirs.empty() && root == nullptr) {
    return new TreeNode(val);
  } 

  Dir next = dirs.front();
  dirs.pop();

  if (next == Dir::LEFT) {
    root->left = insert(val, root->left, dirs);
  } else if (next == Dir::RIGHT) {
    root->right = insert(val, root->right, dirs);
  }

  return root;
}

bool operator==(const TreeNode &lhs, const TreeNode &rhs)
{
  return lhs.val == rhs.val;
}

bool are_equal(const TreeNode *lhs, const TreeNode *rhs)
{
  if (lhs == nullptr && rhs == nullptr) {
    return true;
  } else if (lhs == nullptr && rhs != nullptr) {
    return false;
  } else if (lhs != nullptr && rhs == nullptr) {
    return false;
  } else {
    return *lhs == *rhs && are_equal(lhs->left, rhs->left)
      && are_equal(lhs->right, rhs->right);
  }
}

void is_subtree(const TreeNode *T1, const TreeNode *T2, bool& is)
{
  if (is) {
    return;
  } else if (T1 == nullptr && T2 != nullptr) {
    return;
  } else if (T1 != nullptr && T2 == nullptr) {
    return;
  }else {
    bool are_same = are_equal(T1, T2);
    if (!are_same) {
      is_subtree(T1->left, T2, is);
      is_subtree(T1->right, T2, is);
    } else {
      is = true;
    }
  }
}

TreeNode *build_T1();
TreeNode *build_T2();

int main(int argc, char *argv[])
{
  TreeNode *T1 = build_T1();
  TreeNode *T2 = build_T2();

  bool is = false;
  is_subtree(T1, T2, is);
  std::cout << "T2 is a subtree of T1 == " << (is ? "true" : "false")
    << std::endl;
  return 0;
}

TreeNode *build_T1()
{
  std::queue<Dir> dirs;
  TreeNode *T1 = insert(5, nullptr, dirs);

  dirs.push(Dir::LEFT);
  T1 = insert(10, T1, dirs);
  dirs.push(Dir::RIGHT);
  T1 = insert(12, T1, dirs);

  dirs.push(Dir::LEFT);
  dirs.push(Dir::LEFT);
  T1 = insert(16, T1, dirs);
  dirs.push(Dir::LEFT);
  dirs.push(Dir::RIGHT);
  T1 = insert(92, T1, dirs);
  dirs.push(Dir::RIGHT);
  dirs.push(Dir::LEFT);
  T1 = insert(76, T1, dirs);
  dirs.push(Dir::RIGHT);
  dirs.push(Dir::RIGHT);
  T1 = insert(54, T1, dirs);

  dirs.push(Dir::LEFT);
  dirs.push(Dir::RIGHT);
  dirs.push(Dir::LEFT);
  T1 = insert(100, T1, dirs);

  std::cout << "T1 = ";
  print_tree(std::cout, T1); std::cout << std::endl;
  return T1;
}

TreeNode *build_T2()
{
  std::queue<Dir> dirs;
  TreeNode *T2 = insert(10, nullptr, dirs);

  dirs.push(Dir::LEFT);
  T2 = insert(16, T2, dirs);
  dirs.push(Dir::RIGHT);
  T2 = insert(92, T2, dirs);

  dirs.push(Dir::RIGHT);
  dirs.push(Dir::LEFT);
  T2 = insert(100, T2, dirs);

  std::cout << "T2 = ";
  print_tree(std::cout, T2); std::cout << std::endl;
  return T2;
}
