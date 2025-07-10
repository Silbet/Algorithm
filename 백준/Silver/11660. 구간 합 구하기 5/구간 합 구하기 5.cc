// 11660. 구간 합 구하기 5
#include<iostream>
using namespace std;

int dp[1030][1030];
int board[1030][1030];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> board[i][j];
    }
  }

  dp[1][1] = board[1][1];
  for (int i = 2; i <= n; i++) {
    dp[i][1] = dp[i - 1][1] + board[i][1];
    dp[1][i] = dp[1][i - 1] + board[1][i];
  }

  for (int i = 2; i <= n; i++) {
    for (int j = 2; j <= n; j++) {
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + board[i][j] - dp[i - 1][j - 1];
    }
  }


  for (int i = 0; i < m; i++) {
    int x1, y1, x2, y2, solve;
    cin >> x1 >> y1 >> x2 >> y2;

    solve = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
    cout << solve << "\n";
  }
}