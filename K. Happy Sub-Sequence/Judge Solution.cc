#include<bits/stdc++.h>

using namespace std;

/***template***/
#define ll                   long long
#define dd                   double
#define scl(n)               scanf("%lld",&n)
#define scd(n)               scanf("%lf",&n)
#define pi                   pair<ll,ll>
#define pb                   push_back
#define mp                   make_pair
#define uu                   first
#define vv                   second
#define FOR(i,n)             for(ll i=1;i<=n;i++)
#define LOOP(i,n)            for(ll i=0;i<n;i++)
#define FOOR(i,a,b)          for(ll i=a;i<=b;i++)
#define LOP(i,a,b)           for(ll i=a;i<b;i++)
#define sorted(s)            sort(s.begin(),s.end())
#define reversed(s)          reverse(s.begin(),s.end())
#define contains(a,b)        (find((a).begin(), (a).end(), (b)) != (a).end())
#define MAXN                 10004
#define pii                  3.1415926536
#define mod                  1000000007
#define eps                  0.0000000001
#define inf                  9000000000000000
#define mstt(a,b)            memset((a),(b),sizeof (a))

//priority_queue<ll, vector<ll>, greater<ll> >q


vector<ll>prime[1000006];
ll cnt[1000005];

ll ara[100005];

ll n, ans = 0;

int main()
{
    FOR(i,1000001)
    {
        for(ll j = i; j <= 1000001; j += i)
            prime[j].push_back(i);
    }

    scl(n);
    
    LOOP(i,n)
    {
        scl(ara[i]);
    
        assert(1 <= ara[i] && ara[i] <= 1000000);
    }    
    cnt[0] = 1;

    LOOP(i, n + 1)
    {
        ll sz = prime[ ara[i] ].size();
        for(ll j = sz - 1; j >= 0; j--)
        {
            ll now = prime[ ara[i] ][j];
            ans = (ans + cnt[now - 1]) % mod;
            cnt[now] =(cnt[now] + cnt[now - 1]) % mod;
        }
    }
    
    printf("%lld\n",ans);
}
