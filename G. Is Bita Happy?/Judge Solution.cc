#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()

{
    ll t;
    cin >> t;
    assert(1 <= t && t <= (ll)1e5);

    while(t--) {
        ll a, k, l, r;
        scanf("%lld %lld %lld %lld", &a, &k, &l, &r);
        assert(1 <= a && a <= (ll)1e9);
        assert(1 <= l && l <= (ll)1e9);
        assert(1 <= r && r <= (ll)1e9);
        assert(l <= r);
        assert(0 <= k && k <= 30);

        if(!( (a >> k) & 1) ) {
            printf("Even\n");
            continue;
        }

        if(k == 0) {
            ll odd = (r - l + 1) / 2;
            if( (r - l + 1) % 2 == 1 && l % 2 == 1)
                odd++;

            if(odd % 2 == 1)
                printf("Odd\n");
            else
                printf("Even\n");

            continue;
        }
        else if(k == 1) {
            ll firstOdd = -1;
            for(ll i = l; i <= r; i++) {
                if(i % 2 == 1 && ( (i >> k) & 1)) {
                    firstOdd = i;
                    break;
                }
            }
            ll odd = (r - firstOdd) / 4 + 1;

            if(firstOdd == -1 || odd % 2 == 0)
                printf("Even\n");
            else
                printf("Odd\n");

            continue;
        }

        ll frst, start, stop;
        if((l >> k) & 1)
            frst = l;
        else
            frst = (l | (1 << k)) & (~( (1 << k) - 1) );

        start = frst & (~( (1 << k) - 1) );
        stop = start + (1 << k) - 1;
        if(stop >= r) {
            ll rng = (r - frst + 1);
            ll odd = rng / 2;
            if(rng % 2 == 1 && frst % 2 == 1)
                odd++;

            if(odd % 2 == 1)
                printf("Odd\n");
            else
                printf("Even\n");

            continue;
        }

        ll num1 = 0;
        ll rng = (stop - frst + 1);
        ll odd = rng / 2;
        if(rng % 2 == 1 && frst % 2 == 1)
            odd++;

        //cout << odd << " " << rng << endl;
        if(odd % 2 == 1)
            num1 = 1;

        if( !((r >> k) & 1) ) {
            if(num1)
                printf("Odd\n");
            else
                printf("Even\n");

            continue;
        }

        ll last = r;
        ll lastStart = last & (~( (1 << k) - 1) );

        ll num2 = 0;
        rng = (last - lastStart + 1);
        odd = rng / 2;
        if(rng % 2 == 1 && lastStart % 2 == 1)
            odd++;

        if(odd % 2 == 1)
            num2 = 1;

        //cout << num1 << " " << num2 << endl;
        if((num1 + num2) % 2 == 0)
            printf("Even\n");
        else
            printf("Odd\n");
    }

    return 0;
}
