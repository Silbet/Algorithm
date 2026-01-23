// 4988. 저금
#include<iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  double n, b, m;
  while (cin >> n >> b >> m) {

    int year = 0;
    while (n <= m) {
      year++;
      n += n * (b / 100);
    }
    cout << year << "\n";
  }
}