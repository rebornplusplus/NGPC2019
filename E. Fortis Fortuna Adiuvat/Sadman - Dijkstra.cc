#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;
const int MX=100005;
ll dis[2][MX];
vector <pii> adj[2][MX];
void init(int n)
{
    for(int i=0;i<=n;i++){
        adj[0][i].clear();
        adj[1][i].clear();
        dis[0][i]=dis[1][i]=LLONG_MAX;
    }
}
void dijkstra(int n,int s,int k)
{
    dis[k][s]=0;
    priority_queue <pii,vector<pii>,greater<pii>> q;
    q.push({0,s});
    while(!q.empty()){
        int u=q.top().second;
        ll d=q.top().first;
        q.pop();
        if(dis[k][u]!=d) continue;
        int l=adj[k][u].size();
        for(int i=0;i<l;i++){
            int v=adj[k][u][i].second;
            ll w=adj[k][u][i].first;
            if(d+w<dis[k][v]){
                dis[k][v]=d+w;
                q.push({dis[k][v],v});
            }
        }
    }
}
int main()
{
    int t,c=1;
    scanf("%d",&t);
    while(t--){
        ll w;
        int n,m,x,q,u,v,s,d;
        scanf("%d %d %d %d",&n,&m,&x,&q);
        init(n);
        while(m--){
            scanf("%d %d %lld",&u,&v,&w);
            adj[0][u].push_back({w,v});
            adj[1][v].push_back({w,u});
        }
        dijkstra(n,x,0);
        dijkstra(n,x,1);
        printf("Case %d:\n",c++);
        while(q--){
            scanf("%d %d",&s,&d);
            ll ans=dis[1][s]+dis[0][d];
            if(dis[1][s]==LLONG_MAX || dis[0][d]==LLONG_MAX) ans=-1;
            if(ans==-1) printf("Be seeing ya, John\n");
            else printf("%lld\n",ans);
        }
    }
    return 0;
}
