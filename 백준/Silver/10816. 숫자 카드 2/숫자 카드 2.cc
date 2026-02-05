// 10816. 숫자카드(복습)
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int number[20000005];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    number[tmp + 10000000]++;
  }

  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int tmp;
    cin >> tmp;
    cout << number[tmp + 10000000] << " ";
  }

}