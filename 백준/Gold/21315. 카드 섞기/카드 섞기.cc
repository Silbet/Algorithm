// 21315. 카드 섞기
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<int> reverse_shuffle(int cnt, vector<int> card) {
  for (int i = 0; i <= cnt; i++) {
    int insertIndex = pow(2, i + 1);
    if (insertIndex >= card.size() || i == cnt) insertIndex = card.size();

    vector<int> tmp_card(card.begin(), card.begin() + (int)pow(2, i));
    card.erase(card.begin(), card.begin() + (int)pow(2, i));
    int a = insertIndex - pow(2, i);
    card.insert(card.begin() + (insertIndex - (int)pow(2, i)), tmp_card.begin(), tmp_card.end());
  }

  return card;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int cardCnt;
  cin >> cardCnt;

  vector<int> shuffledCard(cardCnt);
  for (int i = 0; i < cardCnt; i++) {
    cin >> shuffledCard[i];
  }

  int first_k = -1;
  int second_k = -1;
  for (int i = 1; pow(2, i) < cardCnt; i++) {

    for (int j = 1; pow(2, j) < cardCnt; j++) {
      vector<int> card(shuffledCard.begin(), shuffledCard.end());

      // 0부터 <= i 까지(2, k)리버스 섞기
      card = reverse_shuffle(j, card);
      // j도 위와 반복
      card = reverse_shuffle(i, card);
      // 값 비교
      for (int k = 0; k < card.size(); k++) {
        if (card[k] != k + 1) break;

        if (k == card.size() - 1) {
          first_k = i;
          second_k = j;
        }
      }
    }

    if (first_k != -1) break;
  }

  cout << first_k << " " << second_k;
}