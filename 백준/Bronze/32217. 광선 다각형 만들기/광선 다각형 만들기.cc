// 32217. 광선 다각형 만들기
#include<iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;

  int result = (n - 1) * 180;

  for (int i = 0; i < n; i++) {
    int angle;
    cin >> angle;
    result -= angle * 2;
  }

  cout << result;
}