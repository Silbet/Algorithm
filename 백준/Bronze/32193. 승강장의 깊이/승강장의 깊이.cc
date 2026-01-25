// 32193. 승강장의 깊이
#include<iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  int depth = 0;
  for (int i = 0; i < n; i++) {
    int ground, platform;
    cin >> ground >> platform;
    depth += ground - platform;

    cout << depth << " ";
  }
}