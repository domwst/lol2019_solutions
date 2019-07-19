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

int get_rbound(vector<int> v) {
	sort(all(v));
	v.resize(unique(all(v)) - v.begin());
	for (int i = 0; i < len(v); ++i) {
		if (i != v[i]) {
			return i;
		}
	}
	return len(v);
}

bool check(vector<int> v, int m, int k) {
	vector<int> wait(m, 0);
	for (int i = max(0ll, m - k); i < m; ++i) {
		wait[i] = 1;
	}
	int cur = m - k - 1;
	for (auto &x : v) {
		if (x < m && wait[x]) {
			wait[x] = 0;
			if (cur >= 0) {
				wait[cur--] = 1;
			}
		}
	}
	return accumulate(all(wait), 0ll) == 0;
}

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> v(n);
	for (auto &x : v) {
		cin >> x;
		--x;
	}
	reverse(all(v));
	int l = 0, r = get_rbound(v) + 1;
	while (r - l > 1) {
		int c = (r + l) >> 1;
		if (check(v, c, k)) {
			l = c;
		} else {
			r = c;
		}
	}
	cout << l << endl;
}

void run() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		solve();
	}
}