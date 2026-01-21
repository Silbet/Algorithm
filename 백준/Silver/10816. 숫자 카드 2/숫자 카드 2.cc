// 10816. 숫자 카드 2
#include<iostream>
#include<algorithm>
using namespace std;

int card[500005];


int lowerBoundBinarySearch(int target, int n) {
  int st = 0;
  int en = n - 1;

  while (st <= en) {
    int mid = (st + en) / 2;

    if (card[mid] >= target) {
      en = mid - 1;
    }

    if (card[mid] < target) {
      st = mid + 1;
    }
  }

  if (card[st] == target) return st;
  return 0;
}

int upperBoundBinarySearch(int target, int n) {
  int st = 0;
  int en = n - 1;

  while (st <= en) {
    int mid = (st + en) / 2;

    if (card[mid] > target) {
      en = mid - 1;
    }

    if (card[mid] <= target) {
      st = mid + 1;
    }
  }

  if (card[en] == target) return en + 1;
  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> card[i];
  }
  sort(card, card + n);

  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int target;
    cin >> target;

    cout << upperBoundBinarySearch(target, n) - lowerBoundBinarySearch(target, n) << " ";
  }
}