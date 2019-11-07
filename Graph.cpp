#include "Graph.h"

#include <algorithm>

Graph::Node::Node(char c) :
  c(c),
  visited(false)
{}

bool Graph::Node::has_connection(char c)
{
  return std::find_if(adjs.begin(), adjs.end(),
    [&](const Node *adj)
    {
      return adj->c == c;
    }) != adjs.end();
}

std::ostream &operator<<(std::ostream &out, const Graph &graph)
{
  for (const Graph::Node &node : graph.nodes_) {
    out << "( --" << node.c << "-- ) --> ";
    for (const Graph::Node *adj : node.adjs) {
      out << adj->c << " --> ";
    }
    out << std::endl;
  }
  return out;
}

Graph::Graph(const std::vector<Connection> &adj)
{
  for (const auto &connection : adj) {
    add_connection(connection);
  }
}

bool Graph::dfs(char start, char end)
{
  Node *start_n = find_node(start);
  Node *end_n = find_node(end);
  bool ret = false;
  dfs(start_n, end_n, ret);
  return ret;
}

Graph::Node *Graph::find_node(char c)
{
  Node *ret = nullptr;
  for(Node &node : nodes_) {
    if (node.c == c) {
      ret = &node;
      break;
    }
  }
  return ret;
}

void Graph::add_connection(const Connection &connection)
{
  Node *from = find_node(connection.start);
  Node *to = (connection.end != ' ') ?
    find_node(connection.end) :
    nullptr;

  if (from == nullptr) {
    nodes_.push_back(Node(connection.start));
  }

  if (to == nullptr && connection.end != ' ') {
    nodes_.push_back(Node(connection.end));
  }
  from = find_node(connection.start);

  if (connection.end != ' ') {
    to = find_node(connection.end);
    if (not from->has_connection(to->c)) {
      from->adjs.push_back(to);
    }
  }
}

void Graph::dfs(Node *start, Node *end, bool &ret)
{
  if (ret) {
    return;
  } else if (start == nullptr || end == nullptr) {
    return;
  } else if (start->c == end->c) {
    ret = true;
  } else {
    std::list<Node *>::iterator it = start->adjs.begin();
    for (; it != start->adjs.end(); ++it) {
      Node *adj = (*it);
      if (not adj->visited) {
        start->visited = true;
        dfs(adj, end, ret);
      }
    }
  }
}
