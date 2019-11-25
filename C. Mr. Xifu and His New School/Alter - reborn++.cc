#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int to_minutes(string ts) {
	assert(ts.size() == 5);
	assert(ts[2] == ':');
	for(int i=0; i<5; ++i) {
		if(i != 2 and !isdigit(ts[i])) assert(false);
	}

	string hh = ts.substr(0, 2);
	string mm = ts.substr(3, 2);

	int hr = stoi(hh);
	int mn = stoi(mm);

	assert(hr >= 0 and hr < 24);
	assert(mn >= 0 and mn < 60);

	return hr * 60 + mn;
}

const int T = 24 * 60 + 7;
int start[T], finish[T];

const int TC_MAX = 100;
const int N_SUM_MAX = 1000000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t, tc = 0;
	assert(cin >> t);
	assert(t > 0 and t <= TC_MAX);

	int n_sum = 0;

	while(t--) {
		int n;
		assert(cin >> n);
		assert(n > 0);
		n_sum += n;

		memset(start, 0, sizeof start);
		memset(finish, 0, sizeof finish);

		for(int i=0; i<n; ++i) {
			string st, en;
			assert(cin >> st >> en);

			int fr = to_minutes(st);
			int to = to_minutes(en);

			if(fr >= to) {
				++finish[24*60];
				++start[0];
			}

			++start[fr];
			++finish[to];
		}

		int res = 0;
		for(int i=0, cnt=0; i<T; ++i) {
			cnt -= finish[i];
			cnt += start[i];
			res = max(res, cnt);
		}

		cout << "Case #" << ++tc << ": Mr.Xifu needs " << res << " classroom(s)\n";
	}

	string temp;
	assert(!(cin >> temp));

	assert(n_sum <= N_SUM_MAX);

	return 0;
}
