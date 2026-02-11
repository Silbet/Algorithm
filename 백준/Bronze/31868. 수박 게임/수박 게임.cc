// 31868. 수박 게임
#include<iostream>
#include<cmath>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  cout << k / (int)pow(2, n-1);
}