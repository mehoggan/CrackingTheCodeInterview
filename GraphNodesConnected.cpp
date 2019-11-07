#include "Graph.h"

bool route_exists(const std::vector<Connection> &connections,
  char start, char end)
{
  Graph graph(connections);
  return graph.dfs(start, end);
}

int main(int argc, char *argv[])
{
  std::vector<Connection> connections = {
    { 'a', 'e' },
    { 'a', 'c' },
    { 'c', 'd' },
    { 'd', 'c' },
    { 'e', 'c' },
    { 'd', 'b' },
    { 'f', ' ' },
  };

  Graph graph(connections);
  std::cout << "Graph: " << std::endl << graph << std::endl;

  std::cout << "route exists between a --> b = "
    << (route_exists(connections, 'a', 'b') ? "true" : "false") << std::endl;

  std::cout << "route exists between b --> d = "
    << (route_exists(connections, 'b', 'd') ? "true" : "false") << std::endl;

  std::cout << "route exists between a --> e = "
    << (route_exists(connections, 'a', 'e') ? "true" : "false") << std::endl;

  std::cout << "route exists between a --> f = "
    << (route_exists(connections, 'a', 'f') ? "true" : "false") << std::endl;

  std::cout << "route exists between a --> g = "
    << (route_exists(connections, 'a', 'g') ? "true" : "false") << std::endl;

  return 0;
}
