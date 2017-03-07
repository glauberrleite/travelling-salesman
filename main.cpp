#include<iostream>
#include<random>
#include<algorithm>
#include"node.h"

using namespace std;

// Limit of times to search for better solution
int const LIMIT = 10000;

// Pseudo Random generator
std::mt19937 randomGenerator;
std::uniform_int_distribution<std::mt19937::result_type> dist(1,10);

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
  vector<int> newRoute = node->getRoute();

  // Swaping two random indexes
  std::iter_swap(newRoute.begin() + dist(randomGenerator), newRoute.begin() + dist(randomGenerator));

  successor = new Node(newRoute);

  return successor->isConnected() ? successor : buildSuccessor(successor);
}

// Hill-Climbing Algorithm
void optimize(Node * &node, int sequence = 0){

  Node * neighbour = buildSuccessor(node);

  if (*node <= *neighbour) {

    sequence++;

    if(sequence < LIMIT){

      // Keeping on searching better results
      optimize(node, sequence);

    }

    // Solution is optimized

  } else {

    // Found a better solution!
    node = neighbour;

    optimize(node);
  }

}

int main (){

  // Initializing generator
  randomGenerator.seed(std::random_device()());

  // Getting problem
  int start;

  cout << "Type the number of the city where the salesman lives [1...10]" << endl;

  cin >> start;

  // Building arbitrary node
  Node * solution = new Node(start);

  // Searching better candidates
  optimize(solution);

  // Printing Results
  cout << "The route is ";

  printRoute(solution->getRoute());

  cout << "The total distance is ";

  cout << to_string(solution->getScore()) + " km" << endl;

  return 0;
}
