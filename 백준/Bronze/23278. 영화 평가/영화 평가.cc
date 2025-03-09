#include<iostream>
#include<algorithm>
using namespace std;

int rating[52];

int main() {
  int personCnt, lowRatingCnt, highRatingCnt;
  cin >> personCnt >> lowRatingCnt >> highRatingCnt;

  for (int i = 0; i < personCnt; i++) {
    cin >> rating[i];
  }

  sort(rating, rating + personCnt);

  int ratingSum = 0;
  for (int i = lowRatingCnt; i < personCnt - highRatingCnt; i++) {
    ratingSum += rating[i];
  }

  cout.precision(12);
  cout << (double)ratingSum / (personCnt - lowRatingCnt - highRatingCnt);
}