// 21734. SMUPC의 등장
#include<iostream>
#include<string>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  string s;
  cin >> s;

  for (int i = 0; i < s.length(); i++) {
    char alphabet = s[i];

    // 알파벳을 int로 변환 (아스키값 그대로 옴)
    int asciiAlphabet = alphabet;

    // int값의 각 자리수를 더함
    int sum = 0;
    while (asciiAlphabet > 0) {
      sum += asciiAlphabet % 10;
      asciiAlphabet /= 10;
    }

    // 더한 값 만큼 알파벳 출력
    for (int j = 0; j < sum; j++) {
      cout << alphabet;
    }
    cout << "\n";

  }
}