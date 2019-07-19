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
	int n;
	cin >> n;
	string s;
	cin >> s;
	int a, b;
	cin >> a >> b;
	b += a;
	int mn1 = 0, mn2 = b;
	for (auto &x : s) {
		if (x == '+') {
			mn2 += a;
		} else {
			mn1 += a;
		}
		int d = min(mn1, mn2);
		cmin(mn1, d);
		cmin(mn2, d + b);
	}
	cout << min(mn1, mn2) << endl;
}