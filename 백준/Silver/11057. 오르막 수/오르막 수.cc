// 11057. 오르막 수
#include<iostream>
using namespace std;

int dp[10][1002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;

  for (int i = 0; i <= 9; i++) {
    dp[i][1] = 1;
  }

  for (int i = 2; i <= n; i++) {
    
    dp[9][i] = 1;
    for (int j = 8; j >= 0; j--) {
      dp[j][i] = (dp[j + 1][i] + dp[j][i - 1]) % 10007;
    }

  }

  int result = 0;
  for (int i = 0; i <= 9; i++) result += dp[i][n];
  cout << result % 10007;
}