#include<iostream>
using namespace std;

int numOfStone[52];

int main() {
  int typeOfStone, numOfDraw, totalStone = 0;
  cin >> typeOfStone;
  for (int i = 0; i < typeOfStone; i++) {
    cin >> numOfStone[i];
    totalStone += numOfStone[i];
  }

  cin >> numOfDraw;

  double totalProbability = 0;
  for (int i = 0; i < typeOfStone; i++) {
    double probability = 1;

    for (int j = 0; j < numOfDraw; j++) {
      probability *= (numOfStone[i] - j) / (double)(totalStone - j);
    }

    totalProbability += probability;
  }
  cout.precision(10);
  cout << totalProbability;
}