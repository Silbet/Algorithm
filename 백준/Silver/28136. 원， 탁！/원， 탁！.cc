// 28136. 원, 탁!
#include<iostream>
using namespace std;

int plate[1000005];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> plate[i];
  }
  plate[n] = plate[0];

  int count = 0;
  for (int i = 0; i < n; i++) {
    if (plate[i] < plate[i + 1]) continue;

    count++;
  }

  cout << count;
}