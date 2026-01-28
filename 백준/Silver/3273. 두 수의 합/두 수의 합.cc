// 3273. 두 수의 합
#include<iostream>
#include<algorithm>
using namespace std;

int arr[100005];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // 입력
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int x;
  cin >> x;

  // 로직
  sort(arr, arr + n);

  int left = 0;
  int right = n - 1;

  int count = 0;
  while (left < right) {
    int sum = arr[left] + arr[right];

    if (sum == x) {
      count++;
      left++;
      right--;
    }
    else if (sum < x) {
      left++;
    }
    else if (sum > x) {
      right--;
    }
  }

  cout << count;
}