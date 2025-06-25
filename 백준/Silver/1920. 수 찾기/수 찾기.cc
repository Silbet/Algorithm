// 1920. 수 찾기(해시맵 연습)
#include<iostream>
#include<unordered_map>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;

  unordered_map<int, bool> arr;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    arr[tmp] = 1;
  }

  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int tmp;
    cin >> tmp;
    if (arr.count(tmp)) {
      cout << "1\n";
    }
    else {
      cout << "0\n";
    }
  }
}