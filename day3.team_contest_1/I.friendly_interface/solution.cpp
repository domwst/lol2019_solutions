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

struct SparseTable {
	vector<vector<int>> table;
	vector<int> lg;

	SparseTable(const vector<int> &v) {
		int n = len(v);
		table.pb(v);
		for (int i = 1; (1 << i) <= n; ++i) {
			table.pb(vector<int>(n - (1 << i) + 1));
			for (int j = 0; j < len(table.back()); ++j) {
				table[i][j] = min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
			}
		}
		lg.resize(n + 1, -1);
		for (int i = 1; i < n + 1; ++i) {
			lg[i] = lg[i >> 1] + 1;
		}
	}

	int query(int l, int r) {
		int ln = lg[r - l];
		return min(table[ln][l], table[ln][r - (1 << ln)]);
	}
};

vector<vector<int>> g;
vector<int> tin;
vector<int> tour;
vector<int> d;

void dfs(int v, int p = -1, int dpth = 0) {
	tin[v] = len(tour);
	tour.pb(dpth);
	d[v] = dpth;
	for (auto &x : g[v]) {
		if (x == p) {
			continue;
		}
		dfs(x, v, dpth + 1);
		tour.pb(dpth);
	}
}

int lca_d(int u, int v, SparseTable &lca) {
	if (u == v) {
		return u;
	}
	u = tin[u];
	v = tin[v];
	if (u > v) {
		swap(u, v);
	}
	return lca.query(u, v + 1);
}

int get_dist(int u, int v, SparseTable &lca) {
	return d[u] + d[v] - 2 * lca_d(u, v, lca);
}

bool is_between(int w, int u, int v, SparseTable &lca) {
	return get_dist(u, v, lca) == get_dist(u, w, lca) + get_dist(w, v, lca);
}

vector<vector<int>> dir_g;
vector<int> used;

bool check_acyclic(int v) {
	used[v] = 1;
	for (auto &x : dir_g[v]) {
		if (used[x] == 1) {
			return false;
		}
		if (used[x] == 0) {
			if (!check_acyclic(x)) {
				return false;
			}
		}
	}
	used[v] = 2;
	return true;
}

void run() {
	int n;
	cin >> n;
	g.resize(n);
	d.resize(n, -1);
	tin.resize(n, -1);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(0);
	SparseTable lca(tour);
	map<int, int> senders;
	vector<pii> routes;
	int s;
	cin >> s;
	for (int i = 0; i < s; ++i) {
		int s, uid;
		cin >> s >> uid;
		--s;
		senders[uid] = s;
	}
	cin >> s;
	for (int i = 0; i < s; ++i) {
		int r, uid;
		cin >> r >> uid;
		--r;
		routes.pb({senders[uid], r});
	}
	n = len(routes);
	dir_g.resize(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j) {
				continue;
			}
			if (is_between(routes[i].first, routes[j].first, routes[j].second, lca) && routes[i].first != routes[j].first) {
				dir_g[i].pb(j);
			}
			if (is_between(routes[i].second, routes[j].first, routes[j].second, lca) && routes[i].first != routes[j].first) {
				dir_g[j].pb(i);
			}
		}
	}
	used.resize(n, 0);
	for (int i = 0; i < n; ++i) {
		if (used[i] == 0 && !check_acyclic(i)) {
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}