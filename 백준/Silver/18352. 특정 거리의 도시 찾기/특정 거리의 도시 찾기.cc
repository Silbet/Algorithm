// 18352. 특정 거리의 도시 찾기
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int city_cnt, road_cnt, shortest_distance, start_city;
  cin >> city_cnt >> road_cnt >> shortest_distance >> start_city;

  vector<vector<int>> road(city_cnt + 1);
  for (int i = 0; i < road_cnt; i++) {
    int start, end;
    cin >> start >> end;
    road[start].push_back(end);
  }

  vector<int> vis(city_cnt + 1, -1);
  queue<int> Q;

  Q.push(start_city);
  vis[start_city] = 0;

  vector<int> shortest_city;
  while (!Q.empty()) {
    int cur = Q.front(); Q.pop();
    for (int dir = 0; dir < road[cur].size(); dir++) {
      int next = road[cur][dir];

      if (vis[next] != -1) continue;
      
      vis[next] = vis[cur] + 1;

      if (vis[next] == shortest_distance) {
        shortest_city.push_back(next);
      }
      else {
        Q.push(next);
      }
    }
  }

  if (shortest_city.empty())
    cout << -1;
  else {
    sort(shortest_city.begin(), shortest_city.end());
    for (int i = 0; i < shortest_city.size(); i++) {
      cout << shortest_city[i] << "\n";
    }
  }
} 