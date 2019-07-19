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

template<int (*f)(int, int)>
struct SparseTable {
	vector<vector<int>> table;
	vector<int> lg;

	SparseTable(const vector<int> &v) {
		int n = len(v);
		table.pb(v);
		for (int i = 1; (1 << i) <= n; ++i) {
			table.pb(vector<int>(n - (1 << i) + 1));
			for (int j = 0; j < len(table.back()); ++j) {
				table[i][j] = f(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
			}
		}
		lg.resize(n + 1, -1);
		for (int i = 1; i < n + 1; ++i) {
			lg[i] = lg[i >> 1] + 1;
		}
	}

	int query(int l, int r) {
		int ln = lg[r - l];
		return f(table[ln][l], table[ln][r - (1 << ln)]);
	}
};

int mymin(int a, int b) {
	return min(a, b);
}

int mymax(int a, int b) {
	return max(a, b);
}

void run() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto &x : v) {
		cin >> x;
	}
	v.pb(INF);
	++n;
	SparseTable<mymin> t_min(v);
	SparseTable<mymax> t_max(v);
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int d;
		cin >> d;
		int r = 1;
		int ans = 0, ans_l, ans_r;
		for (int l = 0; l < n; ++l) {
			while (r < n && t_max.query(l, r) - t_min.query(l, r) <= d) {
				++r;
			}
			if (cmax(ans, r - l)) {
				ans_l = l;
				ans_r = r - 2;
			}
		}
		cout << ans_l + 1 << " " << ans_r + 1 << endl;
	}
}