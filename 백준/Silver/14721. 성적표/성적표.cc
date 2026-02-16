#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    long long min_rss = -1;
    int ans_a = 0, ans_b = 0;

    for (int a = 1; a <= 100; a++) {
        for (int b = 1; b <= 100; b++) {
            long long cur_rss = 0;
            for (int i = 0; i < n; i++) {
                long long diff = y[i] - ((long long)a * x[i] + b);
                cur_rss += diff * diff;
            }

            if (min_rss == -1 || cur_rss < min_rss) {
                min_rss = cur_rss;
                ans_a = a;
                ans_b = b;
            }
        }
    }

    cout << ans_a << " " << ans_b;
}