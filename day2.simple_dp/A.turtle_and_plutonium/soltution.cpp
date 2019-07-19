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
	int n, m, t;
	cin >> n >> m >> t;
	vector<vector<int>> fld(n, vector<int>(m));
	for (auto &v : fld) {
		for (auto &x : v) {
			cin >> x;
		}
	}
	vector<vector<int>> dp(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (i > 0) {
				cmax(dp[i][j], dp[i - 1][j]);
			}
			if (j > 0) {
				cmax(dp[i][j], dp[i][j - 1]);
			}
			dp[i][j] += fld[i][j];
			if ((i + j + 1) % t == 0) {
				dp[i][j] >>= 1;
			}
		}
	}
	cout << dp.back().back() << endl;
}