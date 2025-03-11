// 1520. 내리막길
#include<iostream>
#include<queue>
#include<utility>
#include<vector>
using namespace std;

int map[502][502];
int visCase[502][502];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

struct compare {
  bool operator()(pair<int, int> a, pair<int, int> b) {
    return map[a.first][a.second] < map[b.first][b.second];
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> map[i][j];
    }
  }

  priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
  pq.push({ 0, 0 });
  visCase[0][0] = 1;

  while (!pq.empty()) {
    pair<int, int> cur = pq.top(); pq.pop();

    for (int dir = 0; dir < 4; dir++) {
      int nx = dx[dir] + cur.first;
      int ny = dy[dir] + cur.second;

      if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
      if (map[cur.first][cur.second] <= map[nx][ny]) continue;
      
      if (visCase[nx][ny] == 0) {
        pq.push({ nx, ny });
      }
      visCase[nx][ny] += visCase[cur.first][cur.second];
    }
  }

  cout << visCase[n - 1][m - 1];
}