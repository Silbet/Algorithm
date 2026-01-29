// 2473. 세 용액
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

long long liquid[5005];
int resultLiquid[3];

long long twoPointer(int n, int i, long long resultValue) {
  int j = 0;
  int k = n - 1;

  while (j < k) {
    long long mixedLiquid = liquid[i] + liquid[j] + liquid[k];

    if (abs(mixedLiquid) < resultValue) {
      resultValue = abs(mixedLiquid);
      resultLiquid[0] = liquid[i];
      resultLiquid[1] = liquid[j];
      resultLiquid[2] = liquid[k];
    }


    if (mixedLiquid < 0) j++;
    else if (mixedLiquid > 0) k--;
    else if (mixedLiquid == 0) {
      resultValue = abs(mixedLiquid);
      resultLiquid[0] = liquid[i];
      resultLiquid[1] = liquid[j];
      resultLiquid[2] = liquid[k];
      return resultValue;
    }

    if (i == j) j++;
    if (i == k) k--;
  }

  return resultValue;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> liquid[i];
  }

  sort(liquid, liquid + n);

  long long resultValue = 3000000000;
  for (int i = 1; i < n - 1; i++) {

    resultValue = twoPointer(n, i, resultValue);

    if (resultValue == 0) break;
  }


  sort(resultLiquid, resultLiquid + 3);

  for (int i = 0; i < 3; i++) {
    cout << resultLiquid[i] << " ";
  }
}