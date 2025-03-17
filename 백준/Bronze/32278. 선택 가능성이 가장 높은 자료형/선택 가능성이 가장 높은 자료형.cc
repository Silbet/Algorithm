// 32278. 선택 가능성이 가장 높은 자료형
#include<iostream>
using namespace std;

int main() {
  long long num;
  cin >> num;

  if (num >= -32768 && num <= 32767) cout << "short";
  else if (num >= -2147483648 && num <= 2147483647) cout << "int";
  else cout << "long long";
}