// 2467. 용액
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

#define TRAIT_MAX 1000000000

struct TraitNumber {
  int value;
  int signValue;

  TraitNumber(int v, int sv) {
    value = v;
    signValue = sv;
  }
};

bool compare(TraitNumber a, TraitNumber b) {
  return a.value > b.value;
}

int main() {
  int n;
  cin >> n;

  vector<TraitNumber> liquid;

  for (int i = 0; i < n; i++) {
    int value;
    cin >> value;

    liquid.push_back(TraitNumber(abs(value), value));
  }

  sort(liquid.begin(), liquid.end(), compare);

  int traitValue = TRAIT_MAX + TRAIT_MAX;
  pair<int, int> targetTraitValue;

  for (int i = 1; i < n; i++) {
    int liquid_1 = liquid[i - 1].signValue;
    int liquid_2 = liquid[i].signValue;

    if (abs(traitValue) > abs(liquid_1 + liquid_2)) {
      traitValue = abs(liquid_1 + liquid_2);
      targetTraitValue = { liquid_1 , liquid_2 };
    }
  }
  if (targetTraitValue.first < targetTraitValue.second) {
    cout << targetTraitValue.first << " " << targetTraitValue.second;
  }
  else {
    cout << targetTraitValue.second << " " << targetTraitValue.first;
  }
}