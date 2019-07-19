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

struct SparceTable {
	vector<vector<int>> table;
	vector<int> lg;

	SparceTable(const vector<int> &v) {
		table.pb(v);
		for (int i = 1; (1 << i) <= len(v); ++i) {
			table.pb(vector<int>(len(v) - (1 << i) + 1));
			for (int j = 0; j < len(table.back()); ++j) {
				table[i][j] = __gcd(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
			}
		}
		lg.resize(len(v) + 1, -1);
		for (int i = 1; i <= len(v); ++i) {
			lg[i] = lg[i >> 1] + 1;
		}
	}

	int query(int l, int r) {
		int ln = lg[r - l];
		return __gcd(table[ln][l], table[ln][r - (1 << ln)]);
	}
};

void run() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &x : a) {
		cin >> x;
	}
	SparceTable t(a);
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int l, r;
		cin >> l >> r;
		--l;
		cout << t.query(l, r) << endl;
	}
}