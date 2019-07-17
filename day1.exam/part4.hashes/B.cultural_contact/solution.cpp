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

const int p = 1234577, M = 1e9 + 7;

void run() {
	string s;
	cin >> s;
	int n = len(s);
	vector<int> pw(26, 1);
	for (int i = 1; i < 26; ++i) {
		pw[i] = (pw[i - 1] * p) % M;
	}
	vector<int> pref(n + 1, 0);
	for (int i = 0; i < n; ++i) {
		pref[i + 1] = pref[i] + pw[s[i] - 'a'];
		if (pref[i + 1] >= M) {
			pref[i + 1] -= M;
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (n % i) {
			continue;
		}
		int h = pref[i];
		bool good = true;
		for (int j = i; j <= n; j += i) {
			if ((pref[j] - pref[j - i] + M) % M != h) {
				good = false;
				break;
			}
		}
		if (good) {
			cout << n / i << endl;
			return;
		}
	}
}