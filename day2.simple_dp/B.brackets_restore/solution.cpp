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
	string s;
	cin >> s;
	int n = len(s);
	vector<vector<int>> dp(n + 1, vector<int>(n, 0));
	dp[0][0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (j > 0 && (s[i] == ')' || s[i] == '?')) {
				dp[i + 1][j - 1] += dp[i][j];
			}
			if (j + 1 < n && (s[i] == '(' || s[i] == '?')) {
				dp[i + 1][j + 1] += dp[i][j];
			}
		}
	}
	cout << dp.back()[0] << endl;
}