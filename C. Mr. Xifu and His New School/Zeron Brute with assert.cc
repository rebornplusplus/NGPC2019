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
#include <unordered_map>
#include <climits>

#define ll long long

#define sl(n) scanf("%lld", &n)
#define ss(n) scanf("%s", n)
#define sf(n) scanf("%lf", &n)

#define PI 3.141592653589
#define INF (1LL<<62)

#define pll pair<ll,ll>

#define eps 1e-9
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define srt(v) sort(v.begin(), v.end())
using namespace std;

ll csum[1440];

int main()
{
	ll n, i, j, k, x, y, z, ts, cs, hs, ms, he, me, ss, se;

	sl(ts);
	assert(1 <= ts && ts <= 100);

	for (cs = 1; cs <= ts; cs++)
	{
		memset(csum, 0, sizeof(csum));
		ll ans = 0;
		sl(n);
		assert(1 <= n && n <= 100000);

		for (i = 1; i <= n; i++)
		{
			scanf("%lld:%lld %lld:%lld", &hs, &ms, &he, &me);

			assert(0 <= hs && hs <= 23);
			assert(0 <= he && he <= 23);

			assert(0 <= ms && ms <= 59);
			assert(0 <= me && me <= 59);

			ss = hs * 60 + ms;
			se = he * 60 + me;

			j = ss;
                        while(1)
			{
				csum[j]++;
				ans = max(ans, csum[j]);
                                j++; 
				if (j == 23*60 + 59 + 1)
				    j = 0;
                                if (j == se)
                                    break;
			}
		}
		printf("Case #%lld: Mr.Xifu needs %lld classroom(s)\n", cs, ans);
	}

	string temp;
	assert(!(cin >> temp));

	return 0;
}
