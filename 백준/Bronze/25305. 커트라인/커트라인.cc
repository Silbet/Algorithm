// 25305. 커트라인
#include<iostream>
#include<algorithm>
using namespace std;

int score[1002];

int main() {
  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    cin >> score[i];
  }

  sort(score, score + n, greater<>());

  cout << score[k - 1];
}