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

std::vector<int>& Node::getRoute(){
  return route;
}

int Node::getScore(){
  return score;
}

bool Node::operator<=(Node& comp){
  return score <= comp.getScore();
}

bool Node::isConnected(){
  if(score == INT_MAX) return 0;
  else return 1;
}

int Node::calculateScore(){
  int score = 0;
  for(int i = 0; i < this->route.size() - 1; ++i)
  {
    int city1 = this->route[i];
    int city2 = this->route[i + 1];

    if (distance[city1 - 1][city2 - 1] == INT_MAX){
      return INT_MAX;
    } else {
      score += distance[city1 - 1][city2 - 1];
    }
  }

  return score;
}

Node::Node(int startingCity){

  this->route.resize(11);

  this->route[0] = startingCity;
  this->route[10] = startingCity;

  // Build an arbitrary route where each city is visited once
  for(int i = startingCity + 1; i < startingCity + this->route.size(); ++i){
    int index = i - startingCity;
    route[index] = (i % 10) != 0 ? i % 10 : 10;
  }

  // Calculating score
  this->score = calculateScore();
}

Node::Node(std::vector<int> &route){
  this->route = route;

  // Calculating score
  this->score = calculateScore();
}
