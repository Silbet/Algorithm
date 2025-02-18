// 1940. 주몽
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int materialCnt, madeNumber;
  cin >> materialCnt >> madeNumber;

  vector<int> material(materialCnt);
  for (int i = 0; i < materialCnt; i++) {
    cin >> material[i];
  }

  sort(material.begin(), material.end());

  int st = 0;
  int en = materialCnt - 1;
  int armorCnt = 0;
  while (st < en) {
    if (material[st] + material[en] == madeNumber) {
      armorCnt++;
      st++;
      en--;
    }
    else if (material[st] + material[en] < madeNumber) {
      st++;
    }
    else {
      en--;
    }
  }

  cout << armorCnt;
}