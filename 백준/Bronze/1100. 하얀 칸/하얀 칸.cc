#include<iostream>
#include<string>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  int pieces = 0;
  for (int i = 0; i < 8; i++) {
    cin >> s;
    for (int j = 0; j < 8; j++) {
      if (s[j] == 'F') {
        if ((i % 2 == 1 && j % 2 == 1) || (i % 2 == 0 && j % 2 == 0)) pieces++;
      }
    }
  }
  cout << pieces;
}