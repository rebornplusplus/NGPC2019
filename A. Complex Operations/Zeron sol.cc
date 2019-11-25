#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <cstdlib>
#include <iterator>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <math.h>
#include <ctime>
#include <cstring>
#include <assert.h>

#define ll long long

#define sl(n) scanf("%lld", &n)
#define ss(n) scanf("%s", n)
#define sf(n) scanf("%lf", &n)

#define PI 2*acos(0.0)
#define INF (1LL<<62)

#define pll pair<ll,ll>

#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define srt(v) sort(v.begin(), v.end())
using namespace std;

ll a[100010];

int main()
{
//    freopen("input.txt", "r", stdin);
	ll n, i, j, k, x, y, z, q, l, r;

	sl(n);
	assert(1 <= n && n <= 1e5);

	sl(q);
	assert(1 <= q && q <= 1e5);

	for (i = 0; i < n; i++)
	{
        sl(a[i]);
        assert(1 <= a[i] && a[i] <= 1e18);
	}

	sort(a, a+n);

    ll add = 0;

    while(q--)
    {
        sl(k);
        assert(k == 1 || k == 2);

        if (k == 1)
        {
            sl(x);
            assert(1 <= x && x <= 1e18);
            add += x;
        }
        else
        {
            sl(l);
            sl(r);
            sl(k);
            assert(1 <= l && l <= 1e18);
            assert(1 <= r && r <= 1e18);
            assert(1 <= k && k <= 1e5);

            ll lo = lower_bound(a, a+n, l+add) - a;
            ll hi = upper_bound(a, a+n, r+add) - a;

            if (hi - lo < k)
                printf("-1\n");
            else printf("%lld\n", a[lo+k-1]-add);
        }
    }
	string temp;
	assert(!(cin >> temp));
	return 0;
}
