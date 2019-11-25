#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
ll dp[2][2][34][34];
vector <ll> num;

ll a, k, l, r;

ll solve(ll isStart, ll isSmall, ll pos)

{
    if(pos == 0)
        return 1;
    ll &ret = dp[isStart][isSmall][pos][k];
    if(ret != -1 && isSmall)
        return ret;

    ll lim, pos2 = num.size() - pos;
    if(isSmall)
        lim = 1;
    else
        lim = num[pos2];

    ll rt = 0;
    if(!isStart) {
        for(ll i = 0; i <= lim; i++) {
            if( (pos2 == num.size() - 1 || pos == k+1) && i == 0)
                continue;
            rt += solve(0, isSmall | i < num[pos2], pos - 1);
        }
    }
    else {
        if(pos <= k)
            return ret = 0;

        for(ll i = 1; i <= lim; i++) {
            if( (pos2 == num.size() - 1 || pos == k+1) && i == 0)
                continue;
            rt += solve(0, isSmall | i < num[pos2], pos - 1);
        }

        if(pos - 1 >= 1)
            rt += solve(1, 1, pos - 1);
    }

    return ret = rt;
}

ll calc(ll n)

{
    if(n <= 0)
        return 0;

    ll tmp = n;
    num.clear();
    while(tmp) {
        num.pb(tmp % 2);
        tmp /= 2;
    }
    reverse(num.begin(), num.end());

    return solve(1, 0, num.size());
}

int main()

{
    ll t, caseno = 0;
    memset(dp, -1, sizeof(dp));
    cin >> t;
    while(t--) {
        scanf("%lld %lld %lld %lld", &a, &k, &l, &r);

        if( !((a >> k) & 1) ) {
            printf("Even\n");
            continue;
        }

        ll ans = calc(r);

        //cout << ans << endl;

        ans -= calc(l - 1);

        if(ans & 1)
            printf("Odd\n");
        else
            printf("Even\n");
    }

    return 0;
}
