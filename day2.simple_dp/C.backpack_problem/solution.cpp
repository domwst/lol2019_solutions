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
	int n, m;
	cin >> n >> m;
	vector<pii> items(n);
	for (auto &x : items) {
		cin >> x.first;
	}
	for (auto &x : items) {
		cin >> x.second;
	}
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, -INF));
	dp[0][0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= m; ++j) {
			cmax(dp[i + 1][j], dp[i][j]);
			if (j + items[i].first <= m) {
				cmax(dp[i + 1][j + items[i].first], dp[i][j] + items[i].second);
			}
		}
	}
	int cur = max_element(all(dp.back())) - dp.back().begin();
	vector<int> ans;
	for (int i = n; i > 0; --i) {
		if (dp[i - 1][cur] != dp[i][cur]) {
			ans.pb(i);
			cur -= items[i - 1].first;
		}
	}
	reverse(all(ans));
	for (auto &x : ans) {
		cout << x << " ";
	}
	cout << endl;
}