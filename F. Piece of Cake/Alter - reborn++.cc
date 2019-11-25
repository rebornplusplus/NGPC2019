#include <bits/stdc++.h>

using namespace std;

typedef long double T;

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

		bad *= (acosl(-1) / 180);

		T bd_sq = ab * ab + ad * ad - 2.0 * ab * ad * cosl(bad);
		T bd = sqrtl(bd_sq);
		T bc = bd + bd;

		// T sin_abd = ad * sinl(bad) / bd;
		// T abd = asin(sin_abd);

		assert(fabs(bd) > EPS);
		T cos_abd = (ab * ab + bd * bd - ad * ad) / (2.0L * ab * bd);
		T abd = acosl(cos_abd);

		T ac_sq = ab * ab + bc * bc - 2.0 * ab * bc * cosl(abd);
		T ac = sqrtl(ac_sq);

		T res = ab * ab + ac * ac;
		
		cout << fixed << setprecision(10) << res << "\n";
	}

	string temp;
	assert(!(cin >> temp));

	return 0;
}
