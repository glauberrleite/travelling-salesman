#include<iostream>
#include"node.h"

using namespace std;

void printRoute(vector<int>& route){

  cout << '[';

  for (int city : route)
    cout << " " + to_string(city) + " ";

  cout << ']' << endl;
}

int main (){

  int start;

  cout << "Type the number of the city where the salesman lives [1...10]" << endl;

  cin >> start;

  // Hill-Climbing Algorithm
  Node solution(start);

  cout << "The route is ";

  printRoute(solution.getRoute());

  cout << "The total distance is ";

  cout << to_string(solution.getScore()) + " km" << endl;

  return 0;
}
