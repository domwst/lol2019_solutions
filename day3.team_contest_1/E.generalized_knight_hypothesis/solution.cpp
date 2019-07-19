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
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (mp(c, d) == mp(1ll, 1ll)) {
		cout << "YES" << endl;
		return;
	}
	if (mp(a, b) == mp(1ll, 1ll)) {
		cout << "NO" << endl;
		cout << 0 << endl;
		return;
	}
	if (a == 1 && c != 1) {
		cout << "NO" << endl;
		cout << 2 << endl;
		cout << 0 << " " << 1 << endl;
		cout << 0 << " " << -1 << endl;
		return;
	}
	if (b == 1 && d != 1) {
		cout << "NO" << endl;
		cout << 2 << endl;
		cout << 1 << " " << 0 << endl;
		cout << -1 << " " << 0 << endl;
		return;
	}
	if (a > c || b > d) {
		cout << "NO" << endl;
		cout << 3 << endl;
		cout << a - 1 << " " << b - 1 << endl;
		cout << 0 << " " << -1 << endl;
		cout << -1 << " " << 0 << endl;
		return;
	}
	cout << "YES" << endl;
}