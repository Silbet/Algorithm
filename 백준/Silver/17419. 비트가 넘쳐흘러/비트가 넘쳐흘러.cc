#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    string k;
    cin >> k;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (k[i] == '1') {
            ans++;
        }
    }

    cout << ans << "\n";
}