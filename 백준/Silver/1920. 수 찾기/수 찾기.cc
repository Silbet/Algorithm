// 1920. 수 찾기
#include<iostream>
#include<algorithm>
using namespace std;

int A[100005];

bool isExsist(int target, int n) {
  int st = 0;
  int en = n - 1;

  while (st <= en) {
    int mid = (st + en) / 2;

    if (A[mid] > target) {
      en = mid - 1;
    }

    if (A[mid] < target) {
      st = mid + 1;
    }

    if (A[mid] == target) {
      return 1;
    }
  }

  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  sort(A, A + n);

  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int target;
    cin >> target;

    cout << isExsist(target, n) << "\n";
  }
}