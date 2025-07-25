#include<iostream>
#include<string>
using namespace std;

int dp[1002][1002];  // 마지막 공통 문자열 index+1
int len[1002][1002];  // 공통 문자열 길이

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string word_1, word_2;
	cin >> word_1 >> word_2;

	// 초기 설정
	if (word_1[0] == word_2[0]) {
		dp[0][0] = 1;
		len[0][0] = 1;
	}
	for (int i = 1; i < word_1.length(); i++) {
		if (dp[0][i - 1] != 0) {
			dp[0][i] = dp[0][i - 1];
			len[0][i] = len[0][i - 1];
		}
		else if (word_2[0] == word_1[i]) {
			dp[0][i] = 1;
			len[0][i] = 1;
		}
	}
	for (int i = 1; i < word_2.length(); i++) {
		if (dp[i - 1][0] != 0) {
			dp[i][0] = dp[i - 1][0];
			len[i][0] = len[i - 1][0];
		}
		else if (word_1[0] == word_2[i]) {
			dp[i][0] = i + 1;
			len[i][0] = 1;
		}
	}

	// dp 시작
	for (int i = 1; i < word_2.length(); i++) {
		for (int j = 1; j < word_1.length(); j++) {

			int same = 0;
			if (word_1[j] == word_2[i] && dp[i][j - 1] <= i) same = 1;

			if (len[i - 1][j] > len[i][j - 1] + same) {
				dp[i][j] = dp[i - 1][j];
				len[i][j] = len[i - 1][j];
			}
			else if (len[i - 1][j] < len[i][j - 1] + same) {
				dp[i][j] = i + 1;
				len[i][j] = len[i][j - 1] + same;
			}
			else {
				if (same) {
					dp[i][j] = dp[i - 1][j];
					len[i][j] = len[i - 1][j];
				}
				else {
					if (dp[i - 1][j] > dp[i][j - 1]) {
						dp[i][j] = dp[i][j - 1];
						len[i][j] = len[i][j - 1];
					}
					else {
						dp[i][j] = dp[i - 1][j];
						len[i][j] = len[i - 1][j];
					}
				}
			}
		}
	}

	cout << len[word_2.length() - 1][word_1.length() - 1];
} 
