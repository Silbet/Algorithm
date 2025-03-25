// 32334. 자석 체스
#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

#define X first
#define Y second

bool board[1002][1002];
int gettingMagnetic[1002][1002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
 
  int boardSize, magneticDistance;
  cin >> boardSize >> magneticDistance;

  vector<pair<int,int>> v;
  for (int i = 0; i < boardSize; i++) {
    for (int j = 0; j < boardSize; j++) {
      cin >> board[i][j];
      if (board[i][j] == 1) {
        v.push_back({i, j});
      }
    }
  }

  for (int magnetic = 0; magnetic < v.size(); magnetic++) {
    int x = v[magnetic].X;
    int y = v[magnetic].Y;

    for (int i = x - magneticDistance; i <= x + magneticDistance; i++) {
      for (int j = y - magneticDistance; j <= y + magneticDistance; j++) {

        if (i < 0 || j < 0 || i >= boardSize || j >= boardSize) continue;
        if (board[i][j]) continue;

        gettingMagnetic[i][j]++;
      }
    }
  }

  pair<int, int> bestSpot;
  int bestMagneticCnt = boardSize * boardSize;
  for (int i = 0; i < boardSize; i++) {
    for (int j = 0; j < boardSize; j++) {
      if (board[i][j] == 1) continue;

      if (gettingMagnetic[i][j] < bestMagneticCnt) {
        bestSpot = {i, j};
        bestMagneticCnt = gettingMagnetic[i][j];
      }
    }
  }

  cout << bestSpot.X + 1 << " " << bestSpot.Y + 1;
  
  if (bestMagneticCnt != 0) cout << "\n" << bestMagneticCnt;
}