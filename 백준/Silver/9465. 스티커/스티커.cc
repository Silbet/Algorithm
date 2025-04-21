// 9465. 스티커
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int test_cnt;
  cin >> test_cnt;

  while (test_cnt--) {
    int sticker_len;
    cin >> sticker_len;

    vector<vector<int>> sticker(2, vector<int>(sticker_len));
    vector<vector<int>> dp(2, vector<int>(sticker_len));

    for (int i = 0; i < sticker_len; i++) {
      cin >> sticker[0][i];
    }
    for (int i = 0; i < sticker_len; i++) {
      cin >> sticker[1][i];
    }

    dp[0][0] = sticker[0][0];
    dp[1][0] = sticker[1][0];
    dp[0][1] = sticker[0][1] + dp[1][0];
    dp[1][1] = sticker[1][1] + dp[0][0];
    for (int i = 2; i < sticker_len; i++) {
      dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + sticker[0][i];
      dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + sticker[1][i];
    }

    int score;
    if (dp[0][sticker_len - 1] > dp[1][sticker_len - 1]) score = dp[0][sticker_len - 1];
    else score = dp[1][sticker_len - 1];

    cout << score << "\n";
  }

}