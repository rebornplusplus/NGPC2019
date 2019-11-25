#include <bits/stdc++.h>
#define LL              long long
#define ll              long long
#define SL(n)           scanf("%lld",&n)
#define LF              double
#define SF(n)           scanf("%lf",&n)

#define pb              push_back
#define ff              first
#define ss              second
#define mp              make_pair

#define ON(n,i)         (n|(1<<i))
#define OFF(n,i)        (n&(~(1<<i)))
#define CHK(n,i)        (n&(1<<i))

#define SET(arr)        memset( arr , -1 , sizeof arr)
#define RESET(arr)      memset( arr,0,sizeof arr)

#define srt(v)          sort(v.begin(),v.end())
#define uniq(v)			v.resize(distance(v.begin(),unique(v.begin(),v.end())))
#define found( s,d )    (s.find(d) != s.end())

#define FOR(i,s,e)      for( LL i = s ; i<=e ; i++ )

#define FILEIN          freopen("in.txt","r",stdin)
#define FILEOUT         freopen("hasnainealter.txt","w",stdout)

/// DEBUG
#define deb             printf("OKA\n")
/// DEBUG ENDS

using namespace std;



int main(){
       

    LL cs;
    SL(cs);
    while(cs--){
        LL L,R;
        SL(L); SL(R);
        unsigned LL ans = 0;
        for( LL i = 1 ; i<=R ; i = i * 2LL ) if( i>=L ) ans+= (unsigned LL)i;
        printf("%llu\n", ans);
    }


return 0;}
