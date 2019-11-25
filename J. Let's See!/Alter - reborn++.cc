#include <bits/stdc++.h>

using namespace std;

int honey_bunny(int x) {
	int ret = 0;
	for(int i=1; i<=x; ++i) ret += x % i;
	return ret;
}

void print_honey(int x) {
	cout << x << ":";
	for(int i=1; i<=x; ++i) cout << " " << (x % i);
	cout << "\n";
}

void precal() {
	static const int N = 1000;

	for(int i=1; i<=N; ++i) {
		if(honey_bunny(i) == honey_bunny(i-1)) {
			// cout << i << " - " << honey_bunny(i) << "\n";
			print_honey(i-1);
			print_honey(i);
			cout << "\n";
		}
	}
}

typedef long long ll;
const int TC_MAX = 100000;
const ll LR_MAX = 1000000000000000000LL;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t, tc = 0;
	assert(cin >> t);
	assert(t >= 1 and t <= TC_MAX);

	while(t--) {
		ll fr, to;
		assert(cin >> fr >> to);
		// if(fr > to) swap(fr, to);
		assert(fr <= to);	// oh man, not this again
		assert(fr >= 1 and fr <= LR_MAX);
		assert(to >= 1 and to <= LR_MAX);

		ll res = 0;
		for(ll p2 = 1; p2 <= LR_MAX; p2 <<= 1) {
			if(p2 >= fr and p2 <= to) {
				res += p2;
			}
		}
		cout << res << "\n";
	}

	string temp;
	assert(!(cin >> temp));

	return 0;
}
