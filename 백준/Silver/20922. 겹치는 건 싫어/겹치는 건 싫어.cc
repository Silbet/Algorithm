// 20922. 겹치는 건 싫어
#include<iostream>
#include<vector>
using namespace std;

int number_count[100002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int sequence_len, limit_number;
  cin >> sequence_len >> limit_number;

  vector<int> sequence(sequence_len);
  for (int i = 0; i < sequence_len; i++) {
    cin >> sequence[i];
  }

  int max_len = 0;
  for (int i = 0, j = 0; i < sequence_len;) {
    // 같은 정수가 K개 이하인 경우
    int number = sequence[i];
    if (number_count[number] < limit_number) {
      number_count[number]++;
      i++;

      if (i - j > max_len) {
        max_len = i - j;
      }
    }
    // 같은 정수가 K개가 된 경우
    else {
      while (number_count[number] >= limit_number) {
        number_count[sequence[j]]--;
        j++;
      }
    }
  }

  cout << max_len;
} 