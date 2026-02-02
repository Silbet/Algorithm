// 1106. 호텔
#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

struct CityPromotion {
  int cost;
  int client;
};

CityPromotion promotion[25];
int dp[25][1005];

int main() {
  int target, cityCount;
  cin >> target >> cityCount;

  for (int i = 1; i <= cityCount; i++) {
    int cost, client;
    cin >> promotion[i].cost >> promotion[i].client;
  }

  // dp[0][x]값 INT_MAX로 채우기
  for (int i = 1; i <= target; i++) {
    dp[0][i] = INT_MAX;
  }

  // dp 로직
  for (int i = 1; i <= cityCount; i++) {
    CityPromotion city = promotion[i];

    for (int j = 1; j <= target; j++) {
      if (j < city.client) {
        dp[i][j] = min(dp[i-1][j], city.cost);
        continue;
      }

      dp[i][j] = min(dp[i-1][j], dp[i][j - city.client] + city.cost);
    }
  }

  cout << dp[cityCount][target];
}