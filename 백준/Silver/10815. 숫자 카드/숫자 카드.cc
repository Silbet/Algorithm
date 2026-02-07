// 10815. 숫자 카드(복습)
#include<iostream>
#include<algorithm>
using namespace std;

int numberCard[500005];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> numberCard[i];
  }

  sort(numberCard, numberCard + n);

  int m;
  cin >> m;

  for (int i = 0; i < m; i++) {
    int target;
    cin >> target;

    int result = binary_search(numberCard, numberCard + n, target);
    
    cout << result << " ";
  }
}