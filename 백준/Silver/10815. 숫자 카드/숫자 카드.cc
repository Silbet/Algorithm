// 10815. 숫자 카드
#include<iostream>
using namespace std;

bool have_card[20000002];

int GetIndex(int card_number) {
  return card_number + 10000000;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int card_number;
    cin >> card_number;

    int card_index = GetIndex(card_number);
    have_card[card_index] = 1;
  }

  int m;
  cin >> m;

  for (int i = 0; i < m; i++) {
    int card_number;
    cin >> card_number;

    int card_index = GetIndex(card_number);
    cout << have_card[card_index] << " ";
  }
}