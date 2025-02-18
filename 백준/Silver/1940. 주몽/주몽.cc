// 1940. 주몽
#include<iostream>
#include<algorithm>
using namespace std;

int material[100002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int materialCnt, madeNumber;
  cin >> materialCnt >> madeNumber;

  for (int i = 0; i < materialCnt; i++) {
    cin >> material[i];
  }

  sort(material, material + materialCnt);

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