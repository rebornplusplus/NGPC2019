#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define LL unsigned long long
#define base 73

#define MAX_N 1000020

LL fh[MAX_N], rh[MAX_N], pw[MAX_N];
gp_hash_table<LL, bool> uniquePal;
char s[MAX_N];
ll len, tot = 0;

LL fHash(ll left, ll right) {
    return left==0? fh[right] : fh[right] - fh[left - 1] * pw[right-left+1];
}

LL rHash(ll &left, ll &right) {
    return right==len-1? rh[left] : rh[left] - rh[right + 1] * pw[right-left+1];
}

bool isPal(ll &left, ll &right) {
    return fHash(left, right) == rHash(left, right);
}

struct palrange {
    ll left, right;
} ans[MAX_N];

bool cmp(const palrange &a, const palrange &b) {

    ll lo = 1, hi = min(a.right-a.left+1, b.right-b.left+1), firstDiff = -1;
    while(lo <= hi) {
        ll mid = (lo + hi) / 2;

        if( fHash(a.left, a.left+mid-1) != fHash(b.left, b.left+mid-1)) {
            firstDiff = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }

    if(firstDiff == -1)
        return (a.right-a.left+1) < (b.right-b.left+1);

    return s[a.left+firstDiff-1] < s[b.left+firstDiff-1];
}

void oddPalGen(ll &i) {

    ll lo = 0, hi  = min(i, len-1 - i), start;
    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
        ll left = i - mid, right = i + mid;

        if(isPal(left, right)) {
            lo = mid + 1;
            start = left;
        }
        else
            hi = mid - 1;
    }

    ll nw = -1;
    lo = 0, hi = i - start;
    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
        ll left = i - mid, right = i + mid;

        LL h = fHash(left, right);
        if(uniquePal.find(h) != uniquePal.end())
            lo = mid + 1;
        else {
            nw = left;
            hi = mid - 1;
        }
    }
    if(nw == -1)
        return;

    for(ll j = nw; j >= start; j--) {
        ll right = i + (i - j);
        uniquePal[ fHash(j, right) ] = 1;
        ans[tot++] = {j, right};
        if(tot >= 1000000) return;
    }
}

void evenPalGen(ll &i) {

    ll lo = 1, hi = min(i+1, len-1 - i), start = -1;
    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
        ll left = i - mid + 1, right = i + mid;

        if(isPal(left, right)) {
            lo = mid + 1;
            start = left;
        }
        else
            hi = mid - 1;
    }
    if(start == -1)
        return;

    ll nw = -1;
    lo = 1, hi = i - start + 1;
    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
        ll left = i - mid + 1, right = i + mid;

        LL h = fHash(left, right);
        if(uniquePal.find(h) != uniquePal.end())
            lo = mid + 1;
        else {
            nw = left;
            hi = mid - 1;
        }
    }
    if(nw == -1)
        return;

    for(ll j = nw; j >= start; j--) {
        ll right = i + (i - j + 1);
        uniquePal[ fHash(j, right) ] = 1;
        ans[tot++] = {j, right};
        if(tot >= 1000000) return;
    }
}

int main()

{
    scanf("%s", s);
    len = strlen(s);
    assert(1 <= len && len <= 1000000);
    for(ll i = 0; s[i] != '\0'; i++)
        assert(s[i] >= 'a' && s[i] <= 'z');

    pw[0] = 1;
    for(ll i = 1; i < MAX_N; i++)
        pw[i] = (pw[i-1] * base);

    for(ll i = 0; s[i] != '\0'; i++) {
        if(i == 0)
            fh[i] = (s[i] - 'a' + 1);
        else
            fh[i] = (fh[i-1] * base) + (s[i] - 'a' + 1);
    }
    for(ll i = len-1; i >= 0; i--) {
        if(i == len-1)
            rh[i] = (s[i] - 'a' + 1);
        else
            rh[i] = (rh[i+1] * base) + (s[i] - 'a' + 1);
    }

    for(ll i = 0; i < len; i++) {
        oddPalGen(i);
        if(tot >= 1000000) break;
        evenPalGen(i);
        if(tot >= 1000000) break;
    }

    sort(ans, ans + tot, cmp);

    ll q;
    cin >> q;
    assert(1 <= q && q <= 100000);
    while(q--) {
        ll k;
        scanf("%lld", &k);
        assert(1 <= k && k <= 1000000);
        if(tot < k) {
            printf("-1\n");
            continue;
        }

        printf("%lld %lld\n", ans[k-1].left + 1, ans[k-1].right + 1);
    }

    string tmp;
    cin >> tmp;
    assert(!tmp.length());

    return 0;
}
