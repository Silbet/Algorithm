// 1764. 듣보잡
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<string> notHear(n);
  vector<string> notSee(m);

  for (int i = 0; i < n; i++) {
    cin >> notHear[i];
  }

  for (int i = 0; i < m; i++) {
    cin >> notSee[i];
  }

  sort(notHear.begin(), notHear.end());
  sort(notSee.begin(), notSee.end());

  int i, j, notHearSeeCnt;
  i = j = notHearSeeCnt = 0;

  vector<string> notHearSeeName;
  while (true) {
    if (notHear[i] == notSee[j]) {
      notHearSeeName.push_back(notHear[i]);
      notHearSeeCnt++;
      i++;
      j++;
    }
    else if (notHear[i] < notSee[j]) i++;
    else j++;

    if (i == n || j == m) break;
  }

  cout << notHearSeeCnt << "\n";
  for (int i = 0; i < notHearSeeName.size(); i++) {
    cout << notHearSeeName[i] << "\n";
  }
}