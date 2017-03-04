#include<vector>
#include<limits.h>

class Node {
public:
  Node(int startingCity = 1);
  Node(std::vector<int> &route);
  std::vector<Node> buildSuccessors();
  static const int distance[10][10];
private:
  int startingCity;
  std::vector<int> route;
};
