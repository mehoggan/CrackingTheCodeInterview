#ifndef GRAPH_INCLUDED
#define GRAPH_INCLUDED

#include <iostream>
#include <list>
#include <vector>

struct Connection
{
  char start;
  char end; // ' ' Denotes nothing connected.
};

class Graph
{
private:
  struct Node
  {
    char c;
    std::list<Node *> adjs;
    bool visited;

    explicit Node(char c);

    bool has_connection(char c);
  };

public:
  friend
  std::ostream &operator<<(std::ostream &out, const Graph &graph);

public:
  explicit Graph(const std::vector<Connection> &adj);

  bool dfs(char start, char end);

private:
  Node *find_node(char c);

  void add_connection(const Connection &connection);

  void dfs(Node *start, Node *end, bool &ret);

private:
  std::list<Node> nodes_;
};


#endif
