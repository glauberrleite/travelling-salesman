#include<iostream>
#include"node.h"

using namespace std;

int main (){

  int start;

  cout << "Type the number of the city where the salesman lives [1...10]" << endl;

  cin >> start;

  // Hill-Climbing Algorithm
  Node solution(start);

  return 0;
}
