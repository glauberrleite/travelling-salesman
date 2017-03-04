#include"node.h"

const int Node::distance[10][10] = {
  {0, 30, 84, 56, INT_MAX, INT_MAX, INT_MAX, 75, INT_MAX, 80},
  {30, 0, 65, INT_MAX, INT_MAX, INT_MAX, 70, INT_MAX, INT_MAX, 40},
  {84, 65, 0, 74, 52, 55, INT_MAX, 60, 143, 48},
  {56, INT_MAX, 74, 0, 135, INT_MAX, INT_MAX, 20, INT_MAX},
  {INT_MAX, INT_MAX, 52, 135, 0, 70, INT_MAX, 122, 98, 80},
  {70, INT_MAX, 55, INT_MAX, 70, 0, 63, INT_MAX, 82, 35},
  {INT_MAX, 70, INT_MAX, INT_MAX, INT_MAX, 63, 0, INT_MAX, 120, 57},
  {75, INT_MAX, 135, 20, 122, INT_MAX, INT_MAX, 0, INT_MAX, INT_MAX},
  {INT_MAX, INT_MAX, 143, INT_MAX, 98, 82, 120, INT_MAX, 0, INT_MAX},
  {80, 40, 48, INT_MAX, 80, 35, 57, INT_MAX, INT_MAX, 0}
};

Node::Node(int startingCity){
  this->startingCity = startingCity;

  route.resize(11);

  route[0] = startingCity;

}

Node::Node(std::vector<int> &route){
  this->route = route;
}

std::vector<Node> Node::buildSuccessors(){
  std::vector<Node> successors;


}
