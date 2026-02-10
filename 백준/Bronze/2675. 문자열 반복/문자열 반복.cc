// 2675. 문자열 반복
#include<iostream>
#include<string>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    int repeat;
    string s;
    cin >> repeat >> s;

    for (int i = 0; i < s.length(); i++) {
      for (int j = 0; j < repeat; j++) {
        cout << s[i];
      }
    }
    cout << "\n";
  }
}