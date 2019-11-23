#include <bits/stdc++.h>

#define long long long
#define pii pair<long, long>
#define x first
#define y second

using namespace std;

const int N = 3e3+5;

int n, m, q, s, e;
bool chk[N];
vector<pii> g[N];
long d1[N], d2[N], dist;
priority_queue<pii, vector<pii>, greater<pii> > Q;

void dijkstra(int s, long d[]) {
    fill_n(d, N, 1e18);
    Q.emplace(d[s] = 0, s);
    while(!Q.empty()) {
        pii now = Q.top(); Q.pop();
        if(d[now.y] != now.x) continue;
        for(pii v : g[now.y]) if(now.x + v.y < d[v.x])
            Q.emplace(d[v.x] = now.x + v.y, v.x);
    }
}

int main() {
    scanf("%d %d %d %d", &n, &m, &s, &e);
    for(int i = 1, a, b, c; i <= m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }
    dijkstra(s, d1);
    dist = d1[e];
    scanf("%d", &q);
    for(int i = 1; i <= n; i++) {
        dijkstra(i, d1);
        if(d1[s] + d1[e] == dist) chk[i] = true;
    }
    while(q--) {
        int u;
        scanf("%d", &u);
        dijkstra(u, d1);
        long ans = 1e18;
        for(int i = 1; i <= n; i++) if(chk[i])
            ans = min(ans, d1[i]);
        printf("%lld\n", ans);
    }

    return 0;
}