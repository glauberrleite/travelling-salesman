#include<vector>
#include<climits>

class Node {
public:
  Node(int startingCity = 1);
  Node(std::vector<int> &route);
  Node* buildSuccessor();
  static const int distance[10][10];
  std::vector<int>& getRoute();
  int getScore();
  bool operator<=(Node &comp);
private:
  int score;
  std::vector<int> route;
  int calculateScore();
};
