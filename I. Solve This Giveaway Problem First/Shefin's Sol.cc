#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 1e9 + 7;

string n;
ll p, num[6], l, n2, np;

ll fastPow(ll x, ll n, ll MOD)
{
    ll ret = 1;
    while (n)
    {
        if (n & 1) ret = (ret * x) % MOD;
        x = (x * x) % MOD;
        n >>= 1;
    }
    return ret % MOD;
}

ll calc(ll a)

{
    ll rem = 0;
    for(ll i = 0; i < n.length(); i++) {
        ll now = n[i] - '0';
        rem = (rem * 10 + now) % a;
    }
    rem = fastPow(rem, p, a);

    ll nom = ( (np - rem) % mod + mod) % mod;
    ll inva = fastPow(a, mod - 2, mod);

    return (nom * inva) % mod;
}

int main()

{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    ll t, cs = 0, sumOfN = 0, mulOfL = 1;
    cin >> t;
    assert(1 <= t && t <= (ll)1e5);
    while(t--) {
        cin >> n >> p >> l;
        sumOfN += n.length();
        assert(1 <= n.length());
        assert(1 <= p && p <= (ll)1e5);
        assert(1 <= l && l <= 5);

        mulOfL = 1;
        for(ll i = 0; i < l; i++) {
            cin >> num[i];
            assert(1 <= num[i] <= (ll)1e9);
            mulOfL *= num[i];
        }

        n2 = 0;
        for(ll i = 0; i < n.length(); i++) {
            ll now = n[i] - '0';
            n2 = (n2 * 10 + now) % mod;
        }
        np = fastPow(n2, p, mod);

        ll lim = (1 << l) - 1;
        ll ans = 0;
        for(ll i = 1; i <= lim; i++) {

            ll lcm = 1, cnt = 0;
            for(ll j = 0; j < l; j++) {
                if( !((i >> j) & 1) )
                    continue;

                ll g = __gcd(lcm, num[j]);
                lcm = (lcm * num[j]) / g;
                cnt++;
            }

            ll tot = calc(lcm);
            if(cnt & 1)
                ans = (ans +  tot) % mod;
            else
                ans = (ans -  tot) % mod;

            if(ans < 0) ans += mod;
        }

        cout << "Case " << ++cs << ": " << ans << endl;
        assert(1 <= mulOfL && mulOfL <= (ll)1e9);
    }

    assert(1 <= sumOfN && sumOfN <= (ll)1e6);

    return 0;
}
