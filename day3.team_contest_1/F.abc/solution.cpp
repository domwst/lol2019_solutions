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

vector<string> fwd = {"A", "B", "C", "AB", "BC", "ABC"};
map<string, int> back;

void init() {
	for (int i = 0; i < len(fwd); ++i) {
		back[fwd[i]] = i;
	}
}

bool check(const vector<int> &p) {
	for (int c = 0; c < 3; ++c) {
		bool was_begin = false, was_end = false;
		for (auto &x : p) {
			if (fwd[x].find(string(1, 'A' + c)) != string::npos) {
				if (was_end) {
					return false;
				}
				was_begin = true;
			} else if (was_begin) {
				was_end = true;
			}
		}
	}
	return true;
}

void run() {
	init();
	vector<vector<string>> tasks(6);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		int idx = back[s];
		getline(cin, s);
		tasks[idx].pb(s);
	}
	vector<int> p;
	for (int i = 0; i < 6; ++i) {
		if (len(tasks[i])) {
			p.pb(i);
		}
	}
	do {
		if (check(p)) {
			for (auto &x : p) {
				for (auto &s : tasks[x]) {
					cout << fwd[x] << s << endl;
				}
			}
			return;
		}
	} while (next_permutation(all(p)));
	cout << "Impossible" << endl;
}