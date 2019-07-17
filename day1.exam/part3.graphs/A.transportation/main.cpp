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

vector<vector<vector<int>>> g;
int n;

int dijkstra(int w) {
	vector<int> dist(n, INF);
	dist[0] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.push({0, 0});
	while (len(q)) {
		auto [d, v] = q.top();
		q.pop();
		if (dist[v] != d) {
			continue;
		}
		for (auto &x : g[v]) {
			if (x[2] >= w && cmin(dist[x[0]], d + x[1])) {
				q.push({dist[x[0]], x[0]});
			}
		}
	}
	return dist.back();
}

void run() {
	int m;
	cin >> n >> m;
	if (n == 1) {
		cout << 10000000 << endl;
		return;
	}
	g.resize(n);
	for (int i = 0; i < m; ++i) {
		int a, b, t, w;
		cin >> a >> b >> t >> w;
		--a, --b;
		w -= 3000000;
		g[a].pb({b, t, w});
		g[b].pb({a, t, w});
	}
	int l = 0, r = INF;
	while (r - l > 1) {
		int c = (r + l) >> 1;
		if (dijkstra(c) > 1440) {
			r = c;
		} else {
			l = c;
		}
	}
	cout << l / 100 << endl;
}