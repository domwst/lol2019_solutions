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

void run() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> fld(n, vector<char>(m));
	for (auto &l : fld) {
		for (auto &x : l) {
			cin >> x;
		}
	}
	queue<pii> q;
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < m - 1; ++j) {
			q.push({i, j});
		}
	}
	while (len(q)) {
		auto [a, b] = q.front();
		q.pop();
		int sm = 0;
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				sm += (fld[a + i][b + j] == '#');
			}
		}
		if (sm == 3) {
			for (int i = 0; i < 2; ++i) {
				for (int j = 0; j < 2; ++j) {
					fld[a + i][b + j] = '#';
				}
			}
			for (int i = -1; i < 2; ++i) {
				for (int j = -1; j < 2; ++j) {
					if (a + i >= 0 && a + i < n - 1 && b + j >= 0 && b + j < m - 1) {
						q.push({a + i, b + j});
					}
				}
			}
		}
	}
	int sm = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			sm += (fld[i][j] == '#');
		}
	}
	cout << sm << endl;
}