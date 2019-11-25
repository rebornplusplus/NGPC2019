#include <iostream>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <cstdlib>
#include <iterator>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <math.h>
#include <ctime>
#include <cstring>
#include <assert.h>

#define ll long long
#define lf double

#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)

#define PI 2*acos(0.0)
#define INFP ((ll)1<<62)
#define INFN (0-(ll)1<<62)

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define srt(v) sort(v.begin(), v.end())
using namespace std;

/*

MAX FLOW Template code credit: Zobayer vai
Link: http://zobayer.blogspot.com/2010/05/maximum-flow-dinitz-algorithm.html

*/

#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))

const int INF = 1000000000;
const int MAXN = 410, MAXE = 80010; //take node and edge twice in case node splitting

int src, snk, nNode, nEdge;
int Q[MAXN], last_edge[MAXN], pro[MAXN], dist[MAXN];
int flow[2 * MAXE], cap[2 * MAXE], prev_edge[2 * MAXE], to[2 * MAXE];

int edge_no[MAXN][MAXN];

inline void init(int _src, int _snk, int _n)
{
	src = _src, snk = _snk, nNode = _n, nEdge = 0;
	SET(last_edge);
}



inline void add_edge(int u, int v, int c, int bi = 0)   //bi = 0 for unidirected or directed
{
//	cout << u << " -> " << v << " " << edge_no[u][v] << endl;
	assert(edge_no[u][v] == -1);
	edge_no[u][v] = nEdge;

	//    cout << "edges " << u << " " << v << " " << c << endl;

	to[nEdge] = v, cap[nEdge] = c, flow[nEdge] = 0, prev_edge[nEdge] = last_edge[u], last_edge[u] = nEdge++;

	to[nEdge] = u, cap[nEdge] = bi == 1 ? c : 0, flow[nEdge] = 0, prev_edge[nEdge] = last_edge[v], last_edge[v] = nEdge++;

}

bool bfs()
{
	int st, en, i, u, v;
	SET(dist);
	dist[src] = st = en = 0;
	Q[en++] = src;
	while (st < en)
	{
		u = Q[st++];
		for (i = last_edge[u]; i >= 0; i = prev_edge[i])
		{
			v = to[i];
			if (flow[i] < cap[i] && dist[v] == -1)
			{
				dist[v] = dist[u] + 1;
				Q[en++] = v;
			}
		}
	}
	return dist[snk] != -1;
}

int dfs(int u, int fl)
{
	if (u == snk) return fl;

	for (int &e = pro[u], v, df; e >= 0; e = prev_edge[e])
	{
		v = to[e];
		if (flow[e] < cap[e] && dist[v] == dist[u] + 1)
		{
			df = dfs(v, min(cap[e] - flow[e], fl));
			if (df > 0)
			{
				flow[e] += df;
				flow[e ^ 1] -= df;
				return df;
			}
		}
	}
	return 0;
}

ll dinitz()
{
	ll ret = 0;
	int df;
	while (bfs())
	{
		for (int i = 0; i <= nNode; i++) pro[i] = last_edge[i];
		while (true)
		{
			df = dfs(src, INF);
			if (df) ret += (ll)df;
			else break;
		}
	}
	return ret;
}


struct edd
{
	ll u, v, lo, up;
} ed[90010];

ll en[MAXN], ou[MAXN];

int main()
{
	//freopen("IO/input01.txt", "r", stdin);
	//  ios_base::sync_with_stdio(0); // no printf/scanf must be present
	ll cs, t, i, j, k, x, y, z, ans, m, p, q, n, num, sz = 0;

	sl(n);
	sl(m);

	assert(1 <= n && n <= 100);
	assert(1 <= m && m <= (n*n-n));

	memset(edge_no, -1, sizeof(edge_no));
	memset(en, 0, sizeof(en));
	memset(ou, 0, sizeof(ou));

	init(0, n + 1, n + 1);

	for (i = 1; i <= m; i++)
	{
		sl(ed[i].u);
		sl(ed[i].v);
		sl(ed[i].lo);
		sl(ed[i].up);

		assert(1 <= ed[i].u && ed[i].u <= n);
		assert(1 <= ed[i].v && ed[i].v <= n);
		assert(ed[i].u != ed[i].v);

		assert(0 <= ed[i].lo && ed[i].lo <= 1e6);
		assert(0 <= ed[i].up && ed[i].up <= 1e6);
		assert(ed[i].lo <= ed[i].up);

		en[ed[i].v] += ed[i].lo;
		ou[ed[i].u] += ed[i].lo;

		add_edge(ed[i].u, ed[i].v, ed[i].up - ed[i].lo);
	}


	for (i = 1; i <= n; i++)
	{
		if (en[i] >= ou[i])
			add_edge(0, i, en[i] - ou[i]);
		else add_edge(i, n + 1, ou[i] - en[i]);
	}

	//   cout << dinitz() << endl;

	dinitz();

	bool flag = 1;

	for (i = 1; i <= n; i++)
	{
		if (edge_no[0][i] == -1)
			continue;

		if (flow[edge_no[0][i]] < cap[edge_no[0][i]])
		{
			printf("NO\n");
			flag = 0;
			break;
		}
	}

	if (flag == 0)
		return 0;

	printf("YES\n");

	for (i = 1; i <= m; i++)
	{
		printf("%lld\n", flow[edge_no[ed[i].u][ed[i].v]] + ed[i].lo);
	}

	string temp;
	assert(!(cin >> temp));
	return 0;
}
