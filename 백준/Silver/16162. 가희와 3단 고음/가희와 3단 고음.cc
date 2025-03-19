// 16162. 가희와 3단 고음
#include<iostream>
#include<vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int personCnt, a, d;
  cin >> personCnt >> a >> d;

  vector<int> note(personCnt);
  for (int i = 0; i < personCnt; i++) {
    cin >> note[i];
  }

  int currentNote = a;
  int pitchLevel = 0;
  for (int i = 0; i < personCnt; i++) {
    if (note[i] == currentNote) {
      pitchLevel++;
      currentNote += d;
    }
  }

  cout << pitchLevel;
}