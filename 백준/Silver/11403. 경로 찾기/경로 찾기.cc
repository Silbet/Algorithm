// 11403. 경로 찾기
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int vis[102][102];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<vector<int>> arr(n);

  for (int i = 0; i < n; i++) {
    int tmp;
    for (int j = 0; j < n; j++) {
      cin >> tmp;
      if (tmp == 1) arr[i].push_back(j);
    }
  }

  queue<int> q;
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < arr[i].size(); j++) {
      q.push(arr[i][j]);
    }

    while (!q.empty()) {
      int next = q.front(); q.pop();

      if (vis[i][next] == 1) continue;

      vis[i][next] = 1;

      for (int j = 0; j < arr[next].size(); j++) {
        q.push(arr[next][j]);
      }
    }
  }

  for (int x = 0; x < n; x++) {
    for (int y = 0; y < n; y++) {
      cout << vis[x][y] << " ";
    }
    cout << "\n";
  }
}