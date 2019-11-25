#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

ll mod = 1e9 + 7;
const ld error = 1e-7;
const double PI = acos(-1); //const ld PI = acosl(-1)

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define eq(x, y) (fabs((x)-(y))<error)
#define bt(i) (1LL<<(i))

#define debug(x) cerr<<#x<<" = "<<(x)<<"\n"
#define hoise cerr<<"hoise - "<<__LINE__<<"\n"
#define tham getchar()
mt19937 rng(chrono::system_clock::now().time_since_epoch().count()); //mt199937_64 for ll

inline ll MOD(ll x, ll m = mod)
{
    ll y = x % m;
    return (y >= 0) ? y: y+m;
}

const int inf = 1e9;
const ll infl = 1e18;
const int nmax = 5e5+10;
///===========================================  template  =======================================================


typedef ll F;
F infflow = 1e14+5;
const int vmax = 105;

struct edge
{
    int v, w;		//edge is v -> w, flow is in that direction too
    F cap, flow;
    F lo;
    edge(int _v = 0, int _w = 0, F _c = 0, F _lo = 0){
        v = _v, w = _w, cap = _c, flow = 0, lo = _lo;
    }

	//u represents from which vertex we request the function
    F flowfrom(int u) {return (u == v)? flow : -flow;}
    int other(int u) {return (u == v)? w: v;}
    F rescap(int u) {return (u == v)? cap - flow: flow;}
    void sendflow(int u, F f) {flow += (u == v)? f: -f;}
};

vector<edge> E;
vector<int> adj[vmax];

inline void addEdge(int v, int w, F c, F lo)		//add edge from v to w
{
    E.push_back(edge(v, w, c, lo));
    adj[v].push_back(E.size()-1);
    adj[w].push_back(E.size()-1);
}


int level[vmax];		//level array
int ptr[vmax];			//ptr to edges in adjacency list
inline bool bfs(int s, int t)
{
    memset(level, -1, sizeof(level));
    queue<int> q;
    q.push(s);
    level[s] = 0;
    while(!q.empty()){
        s = q.front();
        q.pop();
        if(s == t) break;
        ptr[s] = 0;
        for(auto i: adj[s]){
            int v = E[i].other(s);
            if(level[v] > -1 || E[i].rescap(s) == 0) continue;

            level[v] = level[s]+1;
            q.push(v);
        }
    }
    return (level[t] > -1);
}

F augment(int u, F flow, int t)		//dfs
{
    if(u == t || flow == 0) return flow;
    for(int &i = ptr[u]; i<adj[u].size() ; i++){
        edge &e = E[adj[u][i]];
        int v = e.other(u);
        if(level[v] != level[u] + 1 || e.rescap(u) == 0) continue;

        F sentflow = augment(v, min(flow, e.rescap(u)), t);
        if(sentflow){
	        e.sendflow(u, sentflow);
			return sentflow;
        }
    }
	level[u] = -1;
    return 0;
}

inline F maxflow(int s, int t)		//s - source, t - sink
{
    F ret = 0, tmp;
    while(bfs(s, t))
    	while(tmp = augment(s, infflow, t))
	        ret += tmp;
    return ret;
}



int acc[vmax];

int main(){
    FASTIO
    int n, m;
    cin>>n>>m;
    for(int i = 0; i<m; i++){
        int v, w;
        F lo, hi;
        cin>>v>>w>>lo>>hi;
        addEdge(v, w, hi-lo, lo);
        acc[v] -= lo;
        acc[w] += lo;
    }

    F tmp1 = 0, tmp2 = 0;
    for(int i = 1; i<=n; i++){
        if(acc[i] > 0){
            addEdge(0, i, acc[i], -1);
            tmp1 += acc[i];
        }
        else if(acc[i] < 0){
            addEdge(i, n+1, -acc[i], -1);
            tmp2 -= acc[i];
        }
    }

    assert(tmp1 == tmp2);

    F tmp = maxflow(0, n+1);
    if(tmp != tmp1){
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    for(int i = 0; i<m; i++){
        cout<<E[i].flowfrom(E[i].v) + E[i].lo<<"\n";
    }
    return 0;
}
