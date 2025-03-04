// 17141. 연구소 2
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int company[52][52];
int vis[52][52];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0 ,1 };

void initVis(int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      vis[i][j] = -1;
    }
  }
}

void initCompany(int virusCnt, vector<pair<int,int>> virusPosition) {
  for (int i = 0; i < virusCnt; i++) {
    pair<int, int> virus = virusPosition[i];

    company[virus.first][virus.second] = 0;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<pair<int, int>> virusSpot;

  int companySize, virusCnt;
  cin >> companySize >> virusCnt;

  for (int i = 0; i < companySize; i++) {
    for (int j = 0; j < companySize; j++) {
      cin >> company[i][j];

      // 2인 경우 company에는 0으로 표기하고 virusSpot에 추가함.
      if (company[i][j] == 2) {
        company[i][j] = 0;
        virusSpot.push_back({ i, j });
      }
    }
  }

  // 조합을 위한 보조 수열 생성
  vector<int> subArray;
  for (int i = 0; i < virusSpot.size(); i++) {
    if (i < virusCnt) subArray.push_back(0);
    else subArray.push_back(1);
  }

  int minimumTime = companySize * companySize;
  do {
    initVis(companySize);
    queue<pair<int, int>> Q;
    vector<pair<int, int>> virusPosition;

    // 바이러스 개수만큼 연구소에 바이러스 심기
    for (int i = 0; i < subArray.size(); i++) {
      if (subArray[i] == 0) {
        pair<int, int> virus = virusSpot[i];

        virusPosition.push_back(virus); // 다른 경우의 수를 대입할 때 연구소를 초기 상태로 만들기 위해 저장
        company[virus.first][virus.second] = 2;
        Q.push({ virus });
        vis[virus.first][virus.second] = 0;
      }
    }

    // BFS 탐색
    while (!Q.empty()) {
      pair<int, int> cur = Q.front(); Q.pop();

      for (int dir = 0; dir < 4; dir++) {
        int nx = cur.first + dx[dir];
        int ny = cur.second + dy[dir];

        if (nx < 0 || ny < 0 || nx >= companySize || ny >= companySize) continue;
        if (company[nx][ny] != 0 || vis[nx][ny] != -1) continue;

        vis[nx][ny] = vis[cur.first][cur.second] + 1;
        Q.push({ nx, ny });
      }
    }

    int time = 0;
    for (int i = 0; i < companySize; i++) {
      for (int j = 0; j < companySize; j++) {
        if (company[i][j] == 0 && vis[i][j] == -1) {
          time = -1;
          break;
        }
        else if (vis[i][j] > time) {
          time = vis[i][j];
        }
      }

      if (time == -1) break;
    }

    if (time != -1 && time < minimumTime) minimumTime = time;

    initCompany(virusCnt, virusPosition);

  } while (next_permutation(subArray.begin(), subArray.end()));

  if (minimumTime == companySize * companySize) minimumTime = -1;
  cout << minimumTime;
}