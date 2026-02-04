// 8892. 팰린드롬
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string word[105];

bool palindrome(string s) {
  for (int i = 0; i < s.length() / 2; i++) {
    if (s[i] != s[s.length() - 1 - i]) {
      return false;
    }
  }

  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    int k;
    cin >> k;

    // 단어 입력
    for (int i = 0; i < k; i++) {
      cin >> word[i];
    }

    string result = "0";
    // n x n 반복
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < k; j++) {
        if (i == j) continue;

        string s = word[i] + word[j];

        if (palindrome(s)) {
          result = s;
          break;
        }
      }

      if (result != "0") break;
    }

    cout << result << "\n";
  }

}