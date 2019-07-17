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

void run();

signed main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	run();
}

typedef tuple<int, int, int> BracketSeq;

BracketSeq Merge(const BracketSeq &s1, const BracketSeq &s2) {
	int m = min(get<0>(s1), get<1>(s2));
	return make_tuple(get<0>(s1) + get<0>(s2) - m, get<1>(s1) + get<1>(s2) - m, get<2>(s1) + get<2>(s2) + m);
}

struct SegTree {
	vector<BracketSeq> tree;
	int n;

	SegTree(int sz) : n(sz) {
		while (n & (n - 1)) {
			++n;
		}
		tree.resize(2 * n - 1, make_tuple(0, 0, 0));
	}

	void update(int idx, const BracketSeq &s) {
		idx += n - 1;
		tree[idx] = s;
		while (idx > 0) {
			idx = (idx - 1) >> 1;
			tree[idx] = Merge(tree[2 * idx + 1], tree[2 * idx + 2]);
		}
	}

	BracketSeq query(int v, int tl, int tr, int l, int r) {
		if (l >= tr || r <= tl) {
			return make_tuple(0, 0, 0);
		}
		if (tl >= l && tr <= r) {
			return tree[v];
		}
		int mid = (tl + tr) >> 1;
		return Merge(query(2 * v + 1, tl, mid, l, r), query(2 * v + 2, mid, tr, l, r));
	}

	BracketSeq query(int l, int r) {
		return query(0, 0, n, l, r);
	}
};

void run() {
	string s;
	cin >> s;
	int n = len(s);
	SegTree t(n);
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(') {
			t.update(i, make_tuple(1, 0, 0));
		} else {
			t.update(i, make_tuple(0, 1, 0));
		}
	}
	int m;
	cin >> m;
	while (m--) {
		int l, r;
		cin >> l >> r;
		--l;
		cout << get<2>(t.query(l, r)) * 2 << endl;
	}
}