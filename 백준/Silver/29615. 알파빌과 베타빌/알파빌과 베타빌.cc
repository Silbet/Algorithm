// 29615. 알파빌과 베타빌
#include<iostream>
using namespace std;

int waiting[1002];
int waitingFriend[1002];


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> waiting[i];
  }

  for (int i = 0; i < m; i++) {
    cin >> waitingFriend[i];
  }

  int count = 0;
  for (int i = 0; i < m; i++) {
    bool flag = 0;

    for (int j = 0; j < m; j++) {
      if (waiting[i] == waitingFriend[j]) {
        flag = 1;
        break;
      }
    }

    if (flag == 0) count++;
  }

  cout << count;
}