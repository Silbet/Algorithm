#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K, M;
    cin >> N >> K >> M;

    vector<int> S(M);
    vector<bool> is_s(N + 1, false);
    for (int i = 0; i < M; i++) {
        cin >> S[i];
        is_s[S[i]] = true;
    }

    vector<int> diff(N + 2, 0);
    for (int s : S) {
        int start = s;
        int end = min(N, s + K);
        diff[start]++;
        diff[end + 1]--;
    }

    vector<int> nightmare_cnt(N + 1, 0);
    int cur = 0;
    for (int i = 1; i <= N; i++) {
        cur += diff[i];
        int can_nightmare = (cur == 0 ? 1 : 0);
        nightmare_cnt[i] = nightmare_cnt[i - 1] + can_nightmare;
    }

    for (int i = 1; i <= N; i++) {
        if (!is_s[i]) {
            int start = i;
            int end = min(N, i + K);
            if (nightmare_cnt[end] - nightmare_cnt[start - 1] == 0) {
                cout << "NO" << "\n";
                return 0;
            }
        }
    }

    cout << "YES" << "\n";
    return 0;
}