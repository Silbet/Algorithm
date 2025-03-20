#include<iostream>
#include<string>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;

    int zeroCnt = 0;
    for (int i = n; i <= m; i++) {
      string num = to_string(i);

      for (int j = 0; j < num.size(); j++) {
        if (num[j] ==  '0') zeroCnt++;
      }
    }
    cout << zeroCnt << "\n";
  }
}