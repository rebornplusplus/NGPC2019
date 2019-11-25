#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX=100005;
ll a[MX];
int main()
{
    int n,q,k,t;
    ll l,r,x,y=0;
    scanf("%d %d",&n,&q);
    for(int i=0;i<n;i++) scanf("%lld",&a[i]);
    sort(a,a+n);
    while(q--){
        scanf("%d",&t);
        if(t==1){
            scanf("%lld",&x);
            y+=x;
        }
        else{
            scanf("%lld %lld %d",&l,&r,&k);
            l+=y,r+=y;
            int i=lower_bound(a,a+n,l)-a;
            i+=k-1;
            if(i>=n || a[i]>r) i=-1;
            ll ans=(i==-1)?-1:a[i]-y;
            printf("%lld\n",ans);
        }
    }
    return 0;
}
