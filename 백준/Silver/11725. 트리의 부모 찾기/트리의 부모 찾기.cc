// 11725. 트리의 부모 찾기
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool vis[100002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int nodeCnt;
  cin >> nodeCnt;
  
  vector<vector<int>> tree(nodeCnt + 1);
  for (int i = 1; i < nodeCnt; i++) {
    int a, b;
    cin >> a >> b;

    tree[a].push_back(b);
    tree[b].push_back(a);
  }

  queue<int> q;
  vector<int> parrent(nodeCnt + 1);
  q.push(1);
  vis[1] = 1;

  while (!q.empty()) {
    int cur = q.front(); q.pop();
    for (int dir = 0; dir < tree[cur].size(); dir++) {
      int next = tree[cur][dir];

      if (vis[next]) continue;

      parrent[next] = cur;
      vis[next] = 1;
      q.push(next);
    }
  }

  for (int i = 2; i <= nodeCnt; i++) {
    cout << parrent[i] << "\n";
  }
}
