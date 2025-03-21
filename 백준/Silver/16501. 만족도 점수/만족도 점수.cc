// 16501. 만족도 점수
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<int> v(8);
  for (int i = 0; i < 8; i++) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  double maxSatisfaction = 0;
  do {
    double aTeam = 1 - abs(v[0] + v[1] - v[2] - v[3]) / 20.0;
    double bTeam = 1 - abs(v[4] + v[5] - v[6] - v[7]) / 20.0;

    double lowerLimit = min(aTeam, bTeam);
    maxSatisfaction = max(lowerLimit, maxSatisfaction);
  } while (next_permutation(v.begin(), v.end()));

  cout << fixed;
  if ((int)(maxSatisfaction * 100) % 10 == 0) cout.precision(1);
  else cout.precision(2);
  
  cout << maxSatisfaction;
}
