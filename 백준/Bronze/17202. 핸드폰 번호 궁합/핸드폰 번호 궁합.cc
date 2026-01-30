#include<iostream>
#include<string>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  string A, B, loveNumber = "";
  cin >> A >> B;
  for (int i = 0; i < 8; i++) {
    loveNumber += A[i];
    loveNumber += B[i];
  }

  for (int n = 0; n < 14; n++) {
    for (int i = 0; i < 15 - n; i++) {
      loveNumber[i] = ((loveNumber[i] - '0') + (loveNumber[i + 1] - '0')) % 10 + '0';
    }
  }

  cout << loveNumber[0] << loveNumber[1];


}