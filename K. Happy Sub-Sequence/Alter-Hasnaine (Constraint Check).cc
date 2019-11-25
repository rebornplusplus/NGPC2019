#include <bits/stdc++.h>`

#define slld(longvalue) scanf("%lld", &longvalue)
#define plld(longvalue) printf("%lld\n", longvalue)

#define slf(longvalue) scanf("%lf", &longvalue)
#define plf(longvalue) printf("%lf\n", longvalue)
#define sc(letter) scanf("%c", &letter)
#define pc(letter) printf("%c", letter)

#define ss(name) scanf("%s", name)
#define ps(name) printf("%s", name)

#define pnew printf("\n")

#define ll long long
#define ull unsigned long long
#define pll pair < long long, long long >
#define pii pair < int, int >

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

#define mxlld LLONG_MAX
#define mnlld -LLONG_MAX

#define mxd 2e8
#define mnd -2e8

#define pi 3.14159265359

#define mod 1000000007


using namespace std;

bool check(ll n, ll pos)
{
	return n & (1LL << pos);
}

ll Set(ll n, ll pos)
{
	return n = n | (1LL << pos);
}

ll arr[100005];

ll dp[1000006];
pll prevdp[1000006];
int main()
{
    ll i, j, k, l, m, n, o, r, q;
    ll testcase;
    ll input, flag, tag, ans;

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);

    slld(n);

    assert(1 <= n && n <= 100000);

    for(i = 1; i <= n; i++)
    {
        slld(arr[i]);

        assert(1 <= arr[i] && arr[i] <= 1000000);
    }

    ans = 0;

    for(i = 1; i <= n; i++)
    {
        dp[0] = 1;
        for(j = 1; j * j <= arr[i]; j++)
        {
            if(arr[i] % j) continue;

            ll y = arr[i] / j;
            ll x = j;

            prevdp[x].first = dp[x];
            prevdp[x].second = i;

            if(prevdp[x - 1].second == i)
            {
                dp[x] += prevdp[x - 1].first % mod;
                dp[x] %= mod;
            }
            else
            {
                dp[x] += dp[x - 1] % mod;

                dp[x] %= mod;
            }

            if(x == y) continue;

            prevdp[y].first = dp[y];
            prevdp[y].second = i;

            if(prevdp[y - 1].second == i)
            {
                dp[y] = (dp[y] + prevdp[y - 1].first) % mod;
            }
            else
            {
                dp[y] = (dp[y] + dp[y - 1]) % mod;
            }

        }

//        cout << dp[1] << " " << dp[2] << endl;
    }

    for(i = 1; i <= 1000000; i++)
    {
        ans += dp[i] % mod;

        ans %= mod;
    }

    cout << ans << endl;

}


