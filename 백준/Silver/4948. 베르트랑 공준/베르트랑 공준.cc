// 4948. 베르트랑 공준
#include<iostream>
using namespace std;
#define range 123456

bool prime[range * 2 + 1];

void sieve(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (prime[i] == 0) continue;

    for (int j = i * 2; j <= n; j += i) {
      prime[j] = 0;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 2; i <= range * 2 + 1; i++) prime[i] = 1;
  sieve(range * 2 + 1);

  while (1) {
    int n;
    cin >> n;
    if (n == 0) break;

    int cnt = 0;
    for (int i = n + 1; i <= n * 2; i++) {
      if (prime[i] == 1) cnt++;
    }
    cout << cnt << "\n";
  }
}