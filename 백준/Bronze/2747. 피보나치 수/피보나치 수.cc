// 2747. 피보나치 수
#include<iostream>
using namespace std;

int fibo[47];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;  // 1~45 범위

  fibo[0] = 0;
  fibo[1] = 1;

  for (int i = 2; i <= n; i++) {
    fibo[i] = fibo[i - 1] + fibo[i - 2];
  }

  cout << fibo[n];
}