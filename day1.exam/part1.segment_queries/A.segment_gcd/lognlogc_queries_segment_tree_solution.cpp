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

struct SegTree {
	vector<int> tree;
	int n;

	SegTree(const vector<int> &v) : n(len(v)) {
		while (n & (n - 1)) {
			++n;
		}
		tree.resize(2 * n - 1, 0);
		for (int i = 0; i < len(v); ++i) {
			tree[i + n - 1] = v[i];
		}
		for (int i = n - 2; i > -1; --i) {
			tree[i] = __gcd(tree[2 * i + 1], tree[2 * i + 2]);
		}
	}

	int query(int v, int tl, int tr, int l, int r) {
		if (tl >= r || tr <= l) {
			return 0;
		}
		if (tl >= l && tr <= r) {
			return tree[v];
		}
		int mid = (tl + tr) >> 1;
		int lval = query(2 * v + 1, tl, mid, l, r);
		int rval = query(2 * v + 2, mid, tr, l, r);
		return __gcd(lval, rval);
	}

	int query(int l, int r) {
		return query(0, 0, n, l, r);
	}
};

void run() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto &x : v) {
		cin >> x;
	}
	SegTree t(v);
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int l, r;
		cin >> l >> r;
		--l;
		cout << t.query(l, r) << endl;
	}
}