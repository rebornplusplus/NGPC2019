#include <cstdio>
#include <queue>
#include <vector>
#include <utility>
#include <cassert>
using namespace std;

#define pli pair<long long, int>
vector<pli>g1[100005];
vector<pli>g2[100005];
long long dist1[100005];
long long dist2[100005];
long long maxVal = 1e18;

void dijkstra1(int source)
{
    priority_queue<pli, vector<pli>, greater<pli> >pq;
    pq.push(pli(0, source));
    dist1[source] = 0;
    int u, sz, v;
    long long uw, vw, cost;
    while(!pq.empty())
    {
        uw = pq.top().first;
        u = pq.top().second;
        // printf("Going from %d, distance %lld\n", u, uw);
        pq.pop();
        if(uw != dist1[u])
            continue;
        sz = g1[u].size();
        for(int i = 0; i < sz; i++)
        {
            vw = g1[u][i].first;
            v = g1[u][i].second;
            // printf("To %d, cost %lld", v, vw);
            cost = dist1[u] + vw;
            if(dist1[v] > cost)
            {
                dist1[v] = cost;
                pq.push(pli(cost, v));
            }
        }
    }
}

void dijkstra2(int source)
{
    priority_queue<pli, vector<pli>, greater<pli> >pq;
    pq.push(pli(0, source));
    dist2[source] = 0;
    int u, sz, v;
    long long uw, vw, cost;
    while(!pq.empty())
    {
        uw = pq.top().first;
        u = pq.top().second;
        pq.pop();
        if(uw != dist2[u])
            continue;
        sz = g2[u].size();
        // printf("Going from %d\n", u);
        for(int i = 0; i < sz; i++)
        {
            vw = g2[u][i].first;
            v = g2[u][i].second;
            cost = dist2[u] + vw;
            // printf("To %d, edge cost %lld, distance: %lld, previous: %lld\n", v, vw, cost, dist2[v]);
            if(dist2[v] > cost)
            {
                dist2[v] = cost;
                pq.push(pli(cost, v));
            }
        }
    }
}

void initGraph(int n)
{
    for(int i = 1; i <= n; i++)
    {
        g1[i].clear();
        g2[i].clear();
        dist1[i] = maxVal;
        dist2[i] = maxVal;
    }
}

int main()
{
    int T, N, M, x, Q, u, v, s, t;
    int cases = 1;
    long long ans, w;
    scanf("%d", &T);
    assert(T<=5);
    while(T--)
    {
        scanf("%d %d %d %d", &N, &M, &x, &Q);
        assert(1 <= N && N <= 1e5 && 1 <= M && M <= 1e5 && 1 <= x && x <= N && 1 <= Q && Q <= 1e5);
        // printf("For %d nodes, %d edges, %d continental, %d queries\n", N, M, x, Q);
        initGraph(N);
        while(M--)
        {
            scanf("%d %d %lld", &u, &v, &w);
            assert(1 <= u && u <= N && 1 <= v && v <= N && 1 <= w && w <= 1e9);
            // printf("Going from %d to %d costs %d\n", u, v, w);
            g1[u].push_back(pli(w, v));
            g2[v].push_back(pli(w, u));
        }
        dijkstra1(x);
        dijkstra2(x);

        printf("Case %d:\n", cases++);
        while(Q--)
        {
            scanf("%d %d", &s, &t);
            assert(1 <= s && s <= N && 1 <= t && t <= N);
            ans = dist2[s] + dist1[t];
            if(ans >= 1e16)
                puts("Be seeing ya, John");
            else
                printf("%lld\n", ans);
        }
    }

    return 0;
}
