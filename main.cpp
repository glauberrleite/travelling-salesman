#include<iostream>
#include"node.h"

using namespace std;

// Limit of times to search for better solution
int const LIMIT = 5;

void printRoute(vector<int>& route){

  cout << '[';

  for (int city : route)
    cout << " " + to_string(city) + " ";

  cout << ']' << endl;
}

Node * buildSuccessor(Node * node){
  Node* successor;

  // We know that we must preserve the first and the last
  // elements. So we have 9 elements with chance to swap,
  // which give (9!)/(2!*(9-2)!) = 36 different possibilities
  std::vector<int> newRoute = node->getRoute();

  successor = new Node(newRoute);

  return successor;
}

// Hill-Climbing Algorithm
void optimize(Node * node, int sequence = 0){

  Node * neighbour = buildSuccessor(node);

  //
  if (node <= neighbour) {

    sequence++;

    if(sequence < LIMIT){

      cout << "Looking for a better solution..." << endl;
      optimize(node, sequence);

    } else{
          cout << "Found the best solution!" << endl;
    }

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
