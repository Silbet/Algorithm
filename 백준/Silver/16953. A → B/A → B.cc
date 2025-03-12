// 16953. A -> B
#include<iostream>
using namespace std;

int main() {
  int stNum, enNum;
  cin >> stNum >> enNum;

  int cnt = 1;
  while (1) {
    cnt++;
    if (enNum % 10 == 1) enNum /= 10;
    else if (enNum % 2 == 0) enNum /= 2;
    else {
      cout << -1;
      break;
    }
  
    if (enNum == stNum) {
      cout << cnt;
      break;
    }
    else if (enNum < stNum) {
      cout << -1;
      break;
    }
  }
}