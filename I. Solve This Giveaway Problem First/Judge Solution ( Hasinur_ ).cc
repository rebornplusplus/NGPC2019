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

#define FILEIN          freopen("input00.txt","r",stdin)
#define FILEOUT         freopen("output00.txt","w",stdout)

/// DEBUG
#define deb             printf("OKA\n")
/// DEBUG ENDS

using namespace std;

#define mod 1000000007

#define lim 100010

char N[ lim ];
LL L[10];

LL strmod( LL m ){
    LL r = 0;
    for( LL i = 0 ; N[i] ; i++ ){
        r = ( r*10 + ( N[i]-'0' ) ) % m;
    }
    return r;
}

LL bigmod( LL a, LL b , LL m){
    LL r = 1;
    a = a%m;
    while(b){
        if(b%2 == 1) r = (r * a )%m;
        b = (b>>1);
        a = ( a * a ) % m;
    }
    return r;
}


int main(){

    //FILEIN;
    //FILEOUT;

    LL cs;
    SL(cs);
    FOR(T,1,cs){
        
        
        scanf(" %s", N);
        LL P;
        SL(P);

        LL S;
        SL(S);
        
        for( LL i = 0 ; i<S; i++ ) SL( L[i] );

        LL ans = 0;

        for( LL mask = 1 ; mask<(1LL<<S) ; mask++ ){
            LL lcm = 1 , gcd = 1 , c = 0;
            for( LL j = 0 ; j<S ; j++ ){
                if( mask&(1LL<<j) ){
                    
                    c++;
                    gcd = __gcd( L[j] , lcm );
                    lcm = lcm * ( L[j] / gcd);
                
                }
            }
            
            /// SOLVE STARTS ///
            
            LL np = bigmod( strmod( mod ) , P , mod );
            LL baad = bigmod( strmod( lcm ) , P , lcm ) % mod;

            LL X = (mod + np - baad) % mod;
            LL Y = bigmod( lcm , mod-2, mod);
            
            if( c % 2 )
                 ans += ( X * Y ) % mod;
            else
                 ans -= ( X * Y ) % mod;

            ans = (ans + mod) % mod;
            


            ///SOLVE ENDS ////

        }

        printf("Case %lld: %lld\n",T,ans);


    }       

return 0;}
