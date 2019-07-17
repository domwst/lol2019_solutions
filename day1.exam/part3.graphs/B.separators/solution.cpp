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

vector<vector<pii>> g;
vector<int> tin, fup;
int timer = 0;

set<pii> denied;

vector<int> ans;

void find_bridges(int v, int p = -1) {
	fup[v] = tin[v] = timer++;
	for (auto &[u, num] : g[v]) {
		if (u == p){
			continue;
		}
		if (tin[u] != -1) {
			cmin(fup[v], tin[u]);
		} else {
			find_bridges(u, v);
			cmin(fup[v], fup[u]);
			if (fup[u] > tin[v] && !denied.count({u, v})) {
				ans.pb(num);
			}
		}
	}
}

void run() {
	int n;
	cin >> n;
	g.resize(n);
	tin.resize(n, -1);
	fup.resize(n, -1);
	vector<vector<int>> clr(n);
	for (int i = 0; i < n; ++i) {
		int c;
		cin >> c;
		--c;
		clr[c].pb(i);
	}
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		g[a].pb({b, i});
		g[b].pb({a, i});
	}
	for (int i = 0; i < n; ++i) {
		if (len(clr[i]) > 1) {
			for (int j = 0; j < len(clr[i]); ++j) {
				int v1 = clr[i][j], v2 = clr[i][(j + 1) % len(clr[i])];
				g[v1].pb({v2, -1});
				g[v2].pb({v1, -1});
				denied.insert({v1, v2});
				denied.insert({v2, v1});
			}
		}
	}
	find_bridges(0);
	cout << len(ans) << endl;
	for (auto &x : ans) {
		cout << x + 1 << " ";
	}
	cout << endl;
}
