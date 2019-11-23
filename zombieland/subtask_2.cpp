#include <bits/stdc++.h>

#define long long long
#define pii pair<long, long>
#define x first
#define y second

using namespace std;

const int N = 2e5+5;

int n, m, q, s, e;
vector<pii> g[N];
int par[N], chk[N];
long d[N];

void dfs(int u, int p) {
    for(pii v : g[u]) if(v.x != p) {
        par[v.x] = u;
        dfs(v.x, u);
    }
}

int main() {
    fill_n(d, N, 1e18);

    scanf("%d %d %d %d", &n, &m, &s, &e);
    for(int i = 1, a, b, c; i <= m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }
    dfs(s, s);
    int now = e;
    while(now) chk[now] = true, now = par[now];

    priority_queue<pii, vector<pii>, greater<pii> > Q;
    for(int i = 1; i <= n; i++) if(chk[i])
        Q.emplace(d[i] = 0, i);
    
    while(!Q.empty()) {
        pii now = Q.top(); Q.pop();
        if(d[now.y] != now.x) continue;
        for(pii v : g[now.y]) if(now.x + v.y < d[v.x])
            Q.emplace(d[v.x] = now.x + v.y, v.x);
    }

    scanf("%d", &q);
    while(q--) {
        int u;
        scanf("%d", &u);
        printf("%lld\n", d[u]);
    }

    return 0;
}