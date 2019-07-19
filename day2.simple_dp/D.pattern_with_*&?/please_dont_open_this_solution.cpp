#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll
#define pb push_back
#define kek pop_back
#define mp make_pair
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int INF = 1e18 + 666;

template<class t1, class t2>
bool cmin(t1 &a, const t2 &b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

template<class t1, class t2>
bool cmax(t1 &a, const t2 &b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

void run();

signed main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	run();
}

void run() {
	string s, t;
	cin >> s >> t;
	int n = len(s), m = len(t);
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));
	dp[0][0] = 0;
	vector<vector<pair<int, string>>> prv(n + 1, vector<pair<int, string>>(m + 1));
	for (int i = 0; i < n; ++i) {
		if (s[i] == '*') {
			dp[i + 1][0] = dp[i][0];
			prv[i + 1][0] = {1, string()};
		}
	}
	for (int j = 0; j < m; ++j) {
		if (t[j] == '*') {
			dp[0][j + 1] = dp[0][j];
			prv[0][j + 1] = {2, string()};
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (isalpha(s[i])) {
				if (isalpha(t[j])) {
					if (s[i] == t[j]) {
						dp[i + 1][j + 1] = dp[i][j] + 1;
						prv[i + 1][j + 1] = {3, string(1, s[i])};
					}
				} else if (t[j] == '?') {
					dp[i + 1][j + 1] = dp[i][j] + 1;
					prv[i + 1][j + 1] = {3, string(1, s[i])};
				} else { // t[j] == '*'
					if (cmin(dp[i + 1][j + 1], dp[i][j + 1] + 1)) {
						prv[i + 1][j + 1] = {1, string(1, s[i])};
					}
					if (cmin(dp[i + 1][j + 1], dp[i + 1][j])) {
						prv[i + 1][j + 1] = {2, string()};
					}
				}
			} else if (s[i] == '?') {
				if (isalpha(t[j])) {
					dp[i + 1][j + 1] = dp[i][j] + 1;
					prv[i + 1][j + 1] = {3, string(1, t[j])};
				} else if (t[j] == '?') {
					dp[i + 1][j + 1] = dp[i][j] + 1;
					prv[i + 1][j + 1] = {3, string(1, (char)('a' + (char)(rnd() % 26)))};
				} else { // t[j] == '*'
					if (cmin(dp[i + 1][j + 1], dp[i][j + 1] + 1)) {
						prv[i + 1][j + 1] = {1, string(1, (char)('a' + (char)(rnd() % 26)))};
					}
					if (cmin(dp[i + 1][j + 1], dp[i + 1][j])) {
						prv[i + 1][j + 1] = {2, string()};
					}
				}
			} else { // s[i] == '*'
				if (isalpha(t[j])) {
					if (cmin(dp[i + 1][j + 1], dp[i + 1][j] + 1)) {
						prv[i + 1][j + 1] = {2, string(1, t[j])};
					}
					if (cmin(dp[i + 1][j + 1], dp[i][j + 1])) {
						prv[i + 1][j + 1] = {1, string()};
					}
				} else if (t[j] == '?') {
					if (cmin(dp[i + 1][j + 1], dp[i + 1][j] + 1)) {
						prv[i + 1][j + 1] = {2, string(1, (char)('a' + (char)(rnd() % 26)))};
					}
					if (cmin(dp[i + 1][j + 1], dp[i][j + 1])) {
						prv[i + 1][j + 1] = {1, string()};
					}
				} else { // t[j] == '*'
					if (cmin(dp[i + 1][j + 1], dp[i][j + 1])) {
						prv[i + 1][j + 1] = {1, string()};
					}
					if (cmin(dp[i + 1][j + 1], dp[i + 1][j])) {
						prv[i + 1][j + 1] = {2, string()};
					}
				}
			}
		}
	}
	if (dp.back().back() == INF) {
		cout << "No solution!" << endl;
		return;
	}
	int cur_i = n, cur_j = m;
	string ans;
	while (cur_i > 0 && cur_j > 0) {
		ans += prv[cur_i][cur_j].second;
		int v = prv[cur_i][cur_j].first;
		if (v & 1) {
			--cur_i;
		}
		if (v & 2) {
			--cur_j;
		}
	}
	reverse(all(ans));
	cout << ans << endl;
}