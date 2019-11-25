#include<bits/stdc++.h>

using namespace std;

#define fRead(x)        freopen(x,"r",stdin)
#define fWrite(x)       freopen (x,"w",stdout)

#define LL              long long
#define ULL             unsigned long long
#define ff              first
#define ss              second
#define pb              push_back
#define INF             1e9
#define PI              acos(-1.0)
#define mk              make_pair
#define pii             pair<int,int>
#define pll             pair<LL,LL>


#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(a,min(b,min(c,d)))
#define max4(a,b,c,d)   max(a,max(b,max(c,d)))
#define SQR(a)          ((a)*(a))
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define ABS(x)          ((x)<0?-(x):(x))

#define SORT(v)         sort(v.begin(),v.end())
#define REV(v)          reverse(v.begin(),v.end())

#define FastRead        ios_base::sync_with_stdio(0);cin.tie(nullptr);


struct point{
    LL name,val;
    bool operator<(const point &a)const{
        return a.val<val;
    }
};

const int N = 100005;
vector<pair<int,int> >g1[N],g2[N];
LL dis1[N],dis2[N];
int n , m;

void DJ(int s,LL dis[],vector<pair<int,int>>*g)
{
    for(int i = 1;i <= n;i++)dis[i] = 1e18;
    priority_queue<point>Q;
    Q.push({s,0});
    dis[s] = 0;

    while(!Q.empty()){
        point P = Q.top();
        Q.pop();
        int node = P.name;
        if(P.val != dis[node])continue;

        for(int i = 0;i < g[node].size();i++){
            int go = g[node][i].first;
            int cost = g[node][i].second;
            if(dis[node] + cost < dis[go]){
                dis[go] = dis[node] + cost;
                Q.push({go,dis[go]});
            }
        }
    }
}

void solve()
{
    int x,  q;
    cin >> n >> m >> x >> q;
    assert(n >= 1 and n <= 100000 and m >= 1 and m <= 100000 and x >= 1 and x <= n and q >= 1 and q <= 100000);
    for(int i = 1;i <= n;i++)g1[i].clear(),g2[i].clear();
    for(int i = 1;i <= m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        assert(a >= 1 and a <= 100000 and b >= 1 and b <= 100000 and c >= 1 and c <= 1000000000);
        g1[a].pb(mk(b,c));
        g2[b].pb(mk(a,c));
    }
    DJ(x,dis1,g1);
    DJ(x,dis2,g2);
    while(q--){
        int s , t;
        cin >> s >> t;
        assert(s >= 1 and s <= n and t >= 1 and t <= n);
        LL ans = dis1[t] + dis2[s];
        if(ans > 1e16){
            cout << "Be seeing ya, John\n";
        }else{
            cout << ans << "\n";
        }
    }

}
int main()
{
//    fRead("test//test4.txt");
//    fWrite("test//out4.txt");

    FastRead
    int t,cases = 0;
    cin >> t;
    assert(t >= 1 and t <= 5);
    while(t--){
        cout << "Case " << ++cases << ":\n";
        solve();
    }

}
