// 2805. 나무 자르기
#include<iostream>
#include<algorithm>
using namespace std;

int tree[1000005];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> tree[i];
  }

  sort(tree, tree + n);
  
  int st = 0;
  int en = 1000000000;

  while (st <= en) {
    int mid = (st + en) / 2;

    long long sum = 0;
    for (int i = 0; i < n; i++) {
      if (tree[i] > mid) {
        sum += tree[i] - mid;
      }
    }

    if (sum >= m) {
      st = mid + 1;
    }

    if (sum < m) {
      en = mid - 1;
    }
  }

  cout << en;
}