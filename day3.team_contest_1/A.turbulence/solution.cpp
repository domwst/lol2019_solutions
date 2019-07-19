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

namespace std {
	template<>
	struct hash<pii> {
		size_t operator()(const pii &p) const {
			return 894350867 * p.first + 120358087 * p.second;
		}
	};
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

int calc_hash(const string &s, int p, int m) {
	int h = 0;
	for (auto &x : s) {
		h *= p;
		h += x - 'a' + 1;
		h %= m;
	}
	return h;
}

const int p1 = 31, p2 = 37, m1 = 1e9 + 7, m2 = 1e9 + 9;

unordered_set<pii> hashes;

bool gen_ans(int l, int k, string &ans) {
	if (l == 0) {
		return !hashes.count({ calc_hash(ans, p1, m1), calc_hash(ans, p2, m2) });
	}
	for (int i = 0; i < k; ++i) {
		ans += 'a' + i;
		if (gen_ans(l - 1, k, ans)) {
			return true;
		}
		ans.kek();
	}
	return false;
}

void run() {
	int n, k;
	cin >> n >> k;
	if (k == 1) {
		cout << string(n + 1, 'a') << endl;
		return;
	}
	string s;
	cin >> s;
	Hash h1(s, 31, 1e9 + 7), h2(s, 37, 1e9 + 9);
	hashes.rehash(1e7 + 666);
	int expected = 0;
	int cur_p = 1;
	for (int l = 1; ; ++l) {
		cur_p *= k;
		expected += cur_p;
		for (int i = 0; i < n - l + 1; ++i) {
			hashes.insert({ h1.get_hash(i, i + l), h2.get_hash(i, i + l) });
		}
		if (len(hashes) != expected) {
			string ans;
			gen_ans(l, k, ans);
			cout << ans << endl;
			return;
		}
	}
}