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

struct Hash {
	vector<int> p, hash;
	int P, m;

	Hash(const string &s, int P, int m) : P(P), m(m) {
		int n = len(s);
		hash.resize(n + 1, 0);
		p.resize(n + 1, 0);
		p[0] = 1;
		for (int i = 1; i <= n; ++i) {
			p[i] = (p[i - 1] * P) % m;
		}
		for (int i = 0; i < n; ++i) {
			hash[i + 1] = (hash[i] * P + (s[i] - 'a' + 1)) % m;
		}
	}

	int get_hash(int l, int r) {
		int h = (hash[r] - hash[l] * p[r - l]) % m;
		if (h < 0) {
			h += m;
		}
		return h;
	}
};

void run() {
	string s;
	cin >> s;
	int n = len(s);
	Hash h1(s, 31, 1e9 + 7), h2(s, 37, 1e9 + 9);
	vector<pii> hashes;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			hashes.pb({ h1.get_hash(i, j + 1), h2.get_hash(i, j + 1) });
		}
	}
	sort(all(hashes));
	hashes.resize(unique(all(hashes)) - hashes.begin());
	cout << len(hashes) << endl;
}
