// 28706. 럭키 세븐
#include<iostream>
#include<vector>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    bool lucky = false;

    vector<bool> modul_7(7);
    modul_7[1] = true;
    for (int i = 0; i < n; i++) {
      vector<bool> tmp_modul_7(7);

      for (int j = 0; j < 2; j++) {
        char archi_oper;
        int operand;
        cin >> archi_oper >> operand;
       
        for (int k = 0; k < 7; k++) {
          if (modul_7[k] == 0) continue;

          if (archi_oper == '+') {
            tmp_modul_7[(k + operand) % 7] = 1;
          }
          else if (archi_oper == '*') {
            tmp_modul_7[(k * operand) % 7] = 1;
          }
        }
      }
      modul_7 = tmp_modul_7;
    }

    if (modul_7[0] == true) lucky = true;

    if (lucky) cout << "LUCKY";
    else cout << "UNLUCKY";
    cout << "\n";
  }

}