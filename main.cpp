#include<iostream>
#include"node.h"

using namespace std;

void printRoute(vector<int>& route){

  cout << '[';

  for (int city : route)
    cout << " " + to_string(city) + " ";

  cout << ']' << endl;
}

// Hill-Climbing Algorithm
void optimize(Node * node){

  Node * neighbour = node->buildSuccessor();

  if (node <= neighbour) {

    cout << "Found the best solution!" << endl;

  } else {

    cout << "Found a better solution!" << endl;

    node = neighbour;

    optimize(node);
  }

}

int main (){

  int start;

  cout << "Type the number of the city where the salesman lives [1...10]" << endl;

  cin >> start;


  Node * solution = new Node(start);

  optimize(solution);

  // Printing Results
  cout << "The route is ";

  printRoute(solution->getRoute());

  cout << "The total distance is ";

  cout << to_string(solution->getScore()) + " km" << endl;

  return 0;
}
