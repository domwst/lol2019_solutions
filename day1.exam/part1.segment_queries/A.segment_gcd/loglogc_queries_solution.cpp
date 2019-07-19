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

vector<pii> compress(const vector<pii> &v) {
	vector<pii> ans;
	for (auto &x : v) {
		if (!len(ans) || ans.back().second != x.second) {
			ans.pb(x);
		}
	}
	return ans;
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
	vector<vector<pii>> q(n);
	for (int i = 0; i < m; ++i) {
		int l, r;
		cin >> l >> r;
		--l, --r;
		q[r].pb({l, i});
	}
	vector<int> ans(m, 0);
	vector<pii> segs;
	for (int i = 0; i < n; ++i) {
		for (auto &x : segs) {
			x.second = __gcd(x.second, a[i]);
		}
		segs.pb({i, a[i]});
		segs = compress(segs);
		for (auto &x : q[i]) {
			ans[x.second] = prev(lower_bound(all(segs), mp(x.first, INF)))->second;
		}
	}
	for (auto &x : ans) {
		cout << x << endl;
	}
}