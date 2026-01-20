// 1654. 랜선 자르기
#include<iostream>
#include<algorithm>
using namespace std;

int cable[10002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int k, n;
  cin >> k >> n;

  for (int i = 0; i < k; i++) {
    cin >> cable[i];
  }
  sort(cable, cable + k);
  
  long long st = 1;
  long long en = cable[k - 1];

  long long mid;
  while (st <= en) {
    mid = (st + en) / 2;

    int count = 0;
    for (int i = 0; i < k; i++) {
      count += cable[i] / mid;
    }

    if (count >= n) {
      st = mid + 1;
    }
    if (count < n) {
      en = mid - 1;
    }

  }
  cout << en;
}