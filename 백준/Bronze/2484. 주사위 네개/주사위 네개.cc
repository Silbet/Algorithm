// 1106. 호텔
#include<iostream>
#include<algorithm>
using namespace std;

int dice[7];

void initDice() {
  for (int i = 1; i <= 6; i++) {
    dice[i] = 0;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  
  int maximumPrize = 0;
  for (int i = 0; i < n; i++) {
    initDice();

    // 주사위 4번 굴리기
    for (int j = 0; j < 4; j++) {
      int roll;
      cin >> roll;
      dice[roll]++;
    }

    // 상금 계산하기
    int prize = 0;
    int sameTwoEyes = 0;
    for (int j = 1; j <= 6; j++) {
      if (dice[j] == 4) prize = max(j * 5000 + 50000, prize);
      else if (dice[j] == 3) prize = max(j * 1000 + 10000, prize);
      else if (dice[j] == 2 && sameTwoEyes != 0) prize = max(j * 500 + sameTwoEyes * 500 + 2000, prize);
      else if (dice[j] == 2) {
        sameTwoEyes = j;
        prize = max(j * 100 + 1000, prize);
      }
      else if (dice[j] == 1) prize = max(j * 100, prize);
    }

    maximumPrize = max(prize, maximumPrize);
  }

  cout << maximumPrize;
}