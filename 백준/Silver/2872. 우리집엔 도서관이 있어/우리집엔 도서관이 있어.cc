// 2872. 우리집엔 도서관이 있어
#include<iostream>
using namespace std;

int book[300002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int bookCnt;
  cin >> bookCnt;

  for (int i = 1; i <= bookCnt; i++) {
    cin >> book[i];
  }

  int mustSortedBookCnt = 0;
  for (int i = bookCnt; i >= 1; i--) {
    if (book[i] < i + mustSortedBookCnt) {
      mustSortedBookCnt++;
    }
  }

  cout << mustSortedBookCnt;
}