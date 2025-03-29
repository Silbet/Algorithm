// 2421. 저금통
#include<iostream>
#include<string>
using namespace std;

bool prime[1000000];
int dp[1000][1000];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  prime[0] = 1;
  prime[1] = 1;
  
  string n;
  cin >> n;
  int num = stoi(n);
  int maxNum = stoi(n+n);

  for (int i = 2; i*i <= maxNum; i++) {
    
    if (prime[i] == 1) continue;

    for (int j = i*2; j <= maxNum; j += i) {
      prime[j] = 1;
    }
  }


  dp[1][1] = 0;
  for (int i = 2; i <= num; i++) {
    dp[i][1] = dp[i-1][1] + !prime[stoi(to_string(i) + to_string(1))];
  }

  for (int i = 1; i <= num; i++) {
    for (int j = 2; j <= num; j++) {
      int value = stoi(to_string(i) + to_string(j));
      dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + !prime[value];
    }
  }

  cout << dp[num][num];
}