#include <bits/stdc++.h>

using namespace std;

// Max Flow - Dinic

#define INF 2000000000
const int MAX_E=60003;
const int MAX_V=5003;
int ver[MAX_E], cap[MAX_E], nx[MAX_E], last[MAX_V], ds[MAX_V], st[MAX_V], now[MAX_V], edge_count, S, T;

inline void reset()
{
	memset(nx,-1,sizeof(nx));
	memset(last,-1,sizeof(last));
	edge_count=0;
}
inline void addedge(const int v,const int w,const int capacity,const int reverse_capacity)
{
	ver[edge_count]=w; cap[edge_count]=capacity; nx[edge_count]=last[v]; last[v]=edge_count++;
	ver[edge_count]=v; cap[edge_count]=reverse_capacity; nx[edge_count]=last[w]; last[w]=edge_count++;
}
inline bool bfs()
{
	memset(ds,-1,sizeof(ds));
	int a,b;
	a=b=0;
	st[0]=T;
	ds[T]=0;
	while (a<=b)
	{
		int v=st[a++];
		for (int w=last[v];w>=0;w=nx[w])
		{
			if (cap[w^1]>0 && ds[ver[w]]==-1)
			{
				st[++b]=ver[w];
				ds[ver[w]]=ds[v]+1;
			}
		}
	}
	return ds[S]>=0;
}
int dfs(int v,int cur)
{
	if (v==T) return cur;
	for (int &w=now[v];w>=0;w=nx[w])
	{
		if (cap[w]>0 && ds[ver[w]]==ds[v]-1)
		{
			int d=dfs(ver[w],min(cur,cap[w]));
			if (d)
			{
				cap[w]-=d;
				cap[w^1]+=d;
				return d;
			}
		}
	}
	return 0;
}
inline long long flow()
{
	long long res=0;
	while (bfs())
	{
		for (int i=0;i<MAX_V;i++) now[i]=last[i];
		while (1)
		{
			int tf=dfs(S,INF);
			res+=tf;
			if (!tf) break;
		}
	}
	return res;
}

const int N = 107;
const int M = N*N;
int eno[M];

struct edge {
	int fr, to;
	int lb, ub;
} e[M];

int in[N], out[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	for(int i=0; i<m; ++i) {
		cin >> e[i].fr >> e[i].to >> e[i].lb >> e[i].ub;
	}

	reset();
	S = 0, T = n + 3;
	for(int i=0; i<m; ++i) {
		in[e[i].to] += e[i].lb;
		out[e[i].fr] += e[i].lb;
		eno[i] = edge_count;
		addedge(e[i].fr, e[i].to, e[i].ub - e[i].lb, 0);
	}
	for(int i=1; i<=n; ++i) {
		addedge(S, i, in[i], 0);
		addedge(i, T, out[i], 0);
	}

	auto fl = flow();

	if(fl == accumulate(in, in+T+1, 0LL)) {
		cout << "YES\n";
		for(int i=0; i<m; ++i) {
			int passed_flow = e[i].ub - cap[eno[i]];
			cout << passed_flow << "\n";
		}
	}
	else {
		cout << "NO\n";
	}

	return 0;
}
