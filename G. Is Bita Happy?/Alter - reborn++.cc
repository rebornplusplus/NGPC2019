#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define ODD 1
#define EVEN 0

// int check(int a, int pos, int fr, int to) {
// 	ll sum = 0;
// 	for(int i=fr; i<=to; ++i) {
// 		if((a & i) & (1 << pos)) sum += i;
// 	}
// 	return sum % 2;
// }

// returns the parity of the number of 
// values < val where bit 'pos' is set
int solve(int val, int pos) {
	int ret = EVEN;

	for(int i=30; i>=0; --i) {
		bool bit = (val & (1 << i));

		if(pos == i) {
			if(!bit) break;
			continue;
		}

		if(!bit) continue;

		int c = i - (pos < i);
		if(pos == 0) {
			if(c != 0) ret ^= EVEN;
			else ret ^= ODD;
		}
		else {
			if(c != 1) ret ^= EVEN;
			else ret ^= ODD;
		}
	}

	return ret;
}

const int TC_MAX = 100000;
const int ALR_MAX = 1000000000;
const int BITPOS_MAX = 30;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	assert(cin >> t);
	assert(t >= 1 and t <= TC_MAX);

	while(t--) {
		int a, k, l, r;
		assert(cin >> a >> k >> l >> r);
		assert(a >= 1 and a <= ALR_MAX);
		assert(k >= 0 and k <= BITPOS_MAX);
		assert(l >= 1 and l <= ALR_MAX);
		assert(r >= 1 and r <= ALR_MAX);

		int res = (((a & (1 << k)) > 0) & (solve(r+1, k) ^ solve(l, k)));
		// assert(res == check(a, k, l, r));
		cout << (res == ODD ? "Odd" : "Even") << "\n";
	}

	string temp;
	assert(!(cin >> temp));

	return 0;
}
