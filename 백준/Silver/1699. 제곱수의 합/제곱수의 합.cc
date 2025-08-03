// 1699. 제곱수의 합
#include<iostream>
#include<cmath>
#include<climits>
using namespace std;

int dp[100002];
int square[400];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  double num = sqrt(n);
  int max_num = ceil(num);

  for (int i = 1; i <= max_num; i++) {
    square[i] = i * i;
  }

  dp[0] = 0;
  int square_num = 1;
  for (int i = 1; i <= n; i++) {
    if (i >= square[square_num + 1]) square_num++;

    dp[i] = INT_MAX;
    for (int j = 1; j <= square_num; j++) {
      dp[i] = min(dp[i], dp[i - square[j]] + 1);
    }
  }

  cout << dp[n];
}