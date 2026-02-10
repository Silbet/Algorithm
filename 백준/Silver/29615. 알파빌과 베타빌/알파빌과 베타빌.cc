// 29615. 알파빌과 베타빌 (복습)
#include<iostream>
using namespace std;

int waitingList[1002];
bool friendList[1002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> waitingList[i];
  }
  for (int i = 0; i < m; i++) {
    int tmp;
    cin >> tmp;
    friendList[tmp] = 1;
  }

  // 친구들을 위한 대기명단 바꾸는 횟수 탐색
  int count = 0;
  for (int i = 0; i < m; i++) {
    if (!friendList[waitingList[i]]) count++;
  }
  cout << count;
}