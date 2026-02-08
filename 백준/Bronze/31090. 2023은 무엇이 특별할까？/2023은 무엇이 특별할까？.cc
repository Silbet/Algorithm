// 31090. 2023은 무엇이 특별할까?
#include<iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    if ((n + 1) % (n % 100) == 0) cout << "Good" << "\n";
    else cout << "Bye" << "\n";
  }
}