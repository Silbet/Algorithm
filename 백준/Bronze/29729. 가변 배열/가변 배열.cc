// 29729. 가변 배열
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int size, add, sub;
  cin >> size >> add >> sub;

  int count = 0;

  for (int i = 0; i < add + sub; i++) {
    int tmp;
    cin >> tmp;

    if (tmp == 1) {
      count++;
    }
    if (tmp == 0) {
      count--;
    }

    if (count > size) {
      size *= 2;
    }
  }

  cout << size;
}