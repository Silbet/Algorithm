// 1058. 친구
#include<iostream>
#include<queue>
using namespace std;

bool two_friend[55][55];
bool vis[55];

void clearVis(int n) {
  for (int i = 0; i < n; i++) {
    vis[i] = 0;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char isFriend;
      cin >> isFriend;

      if (isFriend == 'Y') two_friend[i][j] = 1;
      if (isFriend == 'N') two_friend[i][j] = 0;
    }
  }

  int max = 0; 
  queue<int> q;
  for (int i = 0; i < n; i++) {
    q.push(i);
    vis[i] = 1;

    int count = 0;
    int depth = 0;
    while (!q.empty()) {
      int cur = q.front(); q.pop();

      depth++;
      for (int next = 0; next < n; next++) {

        if (two_friend[cur][next] == 1 && vis[next] == 0) {
          count++;

          vis[next] = 1;
          if (depth < 2) {
            q.push(next);
          }
        }
      }
    }
    if (count > max) max = count;
    clearVis(n);
  }

  cout << max;
}