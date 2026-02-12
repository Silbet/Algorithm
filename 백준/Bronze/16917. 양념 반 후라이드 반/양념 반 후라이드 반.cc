// 16917. 양념 반 후라이드 반
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a, b, c;
  cin >> a >> b >> c;

  int spicy, fried;
  cin >> spicy >> fried;

  int cash = 0;
  
  if (a + b > c + c) {
    int mixed = min(spicy, fried);
    spicy -= mixed;
    fried -= mixed;
    cash += mixed * c * 2;

    if (a > c + c) {
      cash += spicy * c * 2;
      spicy = 0;
    }
    if (b > c + c) {
      cash += fried * c * 2;
      fried = 0;
    }
  }
  

  cash += spicy * a + fried * b;

  cout << cash;
}