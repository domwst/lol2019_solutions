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

bool check(const vector<int> &a, const vector<int> &b, int h) {
	int cur = 0;
	int n = len(b);
	for (auto &x : a) {
		if (x >= h) {
			continue;
		}
		while (cur < n && x + b[cur] < h) {
			++cur;
		}
		if (cur == n) {
			return false;
		}
		++cur;
	}
	return true;
}

void run() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &x : a) {
		cin >> x;
	}
	int m;
	cin >> m;
	vector<int> b(m);
	for (auto &x : b) {
		cin >> x;
	}
	int l = 0, r = INF;
	while (r - l > 1) {
		int c = (r + l) >> 1;
		if (check(a, b, c)) {
			l = c;
		} else {
			r = c;
		}
	}
	vector<pii> ans;
	int cur = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] >= l) {
			continue;
		}
		while (a[i] + b[cur] < l) {
			++cur;
		}
		ans.pb({i, cur});
		++cur;
	}
	cout << l << " " << len(ans) << endl;
	for (auto &[x, y] : ans) {
		cout << x + 1 << " " << y + 1 << endl;
	}
}