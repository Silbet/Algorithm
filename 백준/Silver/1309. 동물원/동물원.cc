// 1309. 동물원
#include<iostream>
using namespace std;

int dp[100002];

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int cageCnt;
  cin >> cageCnt;

  dp[1] = 3;
  dp[2] = 7;

  for (int i = 3; i <= cageCnt; i++) {
    dp[i] = ( dp[i-1] * 2 + dp[i-2] ) % 9901;
  }

  cout << dp[cageCnt];
}
