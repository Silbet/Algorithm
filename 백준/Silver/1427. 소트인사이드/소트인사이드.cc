// 1427. 소트인사이드
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool compare(char a, char b) {
  return a > b;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> s;

  sort(s.begin(), s.end(), compare);

  cout << s;
}