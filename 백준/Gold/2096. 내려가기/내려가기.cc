// 2096. 내려가기
#include<iostream>
#include<algorithm>
using namespace std;

int board[3];
int max_dp[2][3];
int min_dp[2][3];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int length;
  cin >> length;


  cin >> board[0] >> board[1] >> board[2];

  max_dp[1][0] = min_dp[1][0] = board[0];
  max_dp[1][1] = min_dp[1][1] = board[1];
  max_dp[1][2] = min_dp[1][2] = board[2];

  for (int i = 1; i < length; i++) {
    cin >> board[0] >> board[1] >> board[2];

    max_dp[0][0] = max_dp[1][0];
    max_dp[0][1] = max_dp[1][1];
    max_dp[0][2] = max_dp[1][2];

    max_dp[1][0] = max(max_dp[0][0], max_dp[0][1]) + board[0];
    max_dp[1][1] = max({ max_dp[0][0], max_dp[0][1], max_dp[0][2] }) + board[1];
    max_dp[1][2] = max(max_dp[0][1], max_dp[0][2]) + board[2];

    min_dp[0][0] = min_dp[1][0];
    min_dp[0][1] = min_dp[1][1];
    min_dp[0][2] = min_dp[1][2];

    min_dp[1][0] = min(min_dp[0][0], min_dp[0][1]) + board[0];
    min_dp[1][1] = min({ min_dp[0][0], min_dp[0][1], min_dp[0][2] }) + board[1];
    min_dp[1][2] = min(min_dp[0][1], min_dp[0][2]) + board[2];

  }
  int max_value = max({ max_dp[1][0], max_dp[1][1], max_dp[1][2] });
  int min_value = min({ min_dp[1][0], min_dp[1][1], min_dp[1][2] });

  cout << max_value << " " << min_value;
}