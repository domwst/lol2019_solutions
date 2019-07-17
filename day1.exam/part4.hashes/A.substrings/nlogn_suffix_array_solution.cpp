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

vector<int> calc_suff_array(const string &s) {
	int n = len(s);
	vector<int> cnt(256, 0);
	for (auto &x : s) {
		++cnt[x];
	}
	for (int i = 1; i < 256; ++i) {
		cnt[i] += cnt[i - 1];
	}
	vector<int> p(n);
	for (int i = n - 1; i > -1; --i) {
		p[--cnt[s[i]]] = i;
	}
	vector<int> cl(n, -1);
	int classes = 0;
	cl[p[0]] = classes;
	for (int i = 1; i < n; ++i) {
		if (s[p[i]] != s[p[i - 1]]) {
			++classes;
		}
		cl[p[i]] = classes;
	}
	++classes;
	for (int iter = 0; classes < n; ++iter) {
		for (auto &x : p) {
			x -= (1 << iter);
			if (x < 0) {
				x += n;
			}
		}
		vector<int> cnt(classes, 0);
		for (auto &x : cl) {
			++cnt[x];
		}
		for (int i = 1; i < classes; ++i) {
			cnt[i] += cnt[i - 1];
		}
		vector<int> np(n, -1);
		for (int i = n - 1; i > -1; --i) {
			np[--cnt[cl[p[i]]]] = p[i];
		}
		p = np;
		classes = 0;
		vector<int> ncl(n, -1);
		ncl[p[0]] = classes;
		for (int i = 1; i < n; ++i) {
			int ci = p[i], ni = p[i] + (1 << iter);
			int pci = p[i - 1], pni = p[i - 1] + (1 << iter);
			if (ni >= n) {
				ni -= n;
			}
			if (cl[ci] != cl[pci] || cl[ni] != cl[pni]) {
				++classes;
			}
			ncl[p[i]] = classes;
		}
		++classes;
		cl = ncl;
	}
	return p;
}

vector<int> calc_lcp(const string &s, const vector<int> &suff_arr) {
	int n = len(s);
	vector<int> bp(n, -1);
	for (int i = 0; i < n; ++i) {
		bp[suff_arr[i]] = i;
	}
	vector<int> lcp(n - 1, 0);
	int cur_lcp = 0;
	for (int i = 0; i < n - 1; ++i) {
		--cur_lcp;
		if (cur_lcp < 0) {
			cur_lcp = 0;
		}
		if (bp[i] == n - 1) {
			continue;
		}
		while (s[i + cur_lcp] == s[suff_arr[bp[i] + 1] + cur_lcp]) {
			++cur_lcp;
		}
		lcp[i] = cur_lcp;
	}
	return lcp;
}

void run() {
	string s;
	cin >> s;
	s += '#';
	int ans = len(s) * (len(s) + 1);
	ans >>= 1;
	for (auto &x : calc_lcp(s, calc_suff_array(s))) {
		ans -= x;
	}
	ans -= len(s);
	cout << ans << endl;
}