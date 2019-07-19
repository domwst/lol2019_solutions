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

string bin_division(int r, int k) {
	int cur = 1;
	string res;
	for (int i = 0; i < k + 2; ++i) {
		if (cur >= r) {
			res += '1';
			cur -= r;
		} else {
			res += '0';
		}
		cur <<= 1;
	}
	if (res.back() == '1') {
		res.back() += 1;
		for (int i = len(res) - 1; i > -1; --i) {
			if (res[i] > '1') {
				res[i] -= 2;
				res[i - 1] += 1;
			}
		}
	}
	res.pop_back();
	return res;
}

string mul(string a, int n) {
	int cur = 0;
	for (int i = len(a) - 1; i > -1; --i) {
		cur += (a[i] - '0') * n;
		a[i] = '0' + (cur & 1);
		cur >>= 1;
	}
	return a;
}

string cut(string s, int n) {
	string ans = s.substr(0, n + 1);
	if (ans == s) {
		return ans;
	}
	if (s[n + 1] == '1') {
		ans.back() += 1;
	}
	for (int i = len(ans) - 1; i > -1; --i) {
		if (ans[i] > '1') {
			ans[i] -= 2;
			ans[i - 1] += 1;
		}
	}
	return ans;
}

void run() {
	int n, k, r;
	cin >> n >> k >> r;
	vector<int> ans;
	for (int i = 2; i <= r; ++i) {
		if (cut(mul(bin_division(i, n), i), k) != string() + '1' + string(k, '0')) {
			ans.pb(i);
		}
	}
	cout << len(ans) << endl;
	for (auto &x : ans) {
		cout << x << " ";
	}
	cout << endl;
}