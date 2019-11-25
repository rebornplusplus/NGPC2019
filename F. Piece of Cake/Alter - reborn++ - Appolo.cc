#include <bits/stdc++.h>

using namespace std;

typedef long double T;

const T PI = acosl(-1);
const T EPS = 1e-7;
const T SIDE_MAX = 100000000;
const T ANG_MAX = 180;
const int TC_MAX = 100000;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	assert(cin >> t);
	assert(t > 1 and t < TC_MAX);

	while(t--) {
		T ab, ad, bad;
		assert(cin >> ab >> ad >> bad);
		assert(ab > EPS and ab < SIDE_MAX);
		assert(ad > EPS and ad < SIDE_MAX);
		assert(bad > EPS and bad < ANG_MAX);

		bad *= PI / 180;
		// 2 (AB^2 + 2AD^2 - 2 AB AD cos <BAD)
		T res = ab * ab + 2.0 * ad * ad - 2.0 * ab * ad * cosl(bad);
		res *= 2.0;

		cout << fixed << setprecision(12) << res << "\n";
	}

	string temp;
	assert(!(cin >> temp));

	return 0;
}
