#include <bits/stdc++.h>

#define pii pair<int, int>
#define x first
#define y second

using namespace std;

const int N = 1e5+5;

int n, q;
int deg[N], ans[N], chk[N];
vector<int> g[N];
priority_queue<pii, vector<pii>, greater<pii> > Q;

int main() {
    scanf("%d", &n);
    for(int i = 1, a, b; i < n; i++) {
        scanf("%d %d", &a, &b);
        g[a].emplace_back(b);
        g[b].emplace_back(a);
        ++deg[a], ++deg[b];
    }
    for(int i = 1; i <= n; i++) if(deg[i] == 1)
        Q.emplace(1, i);

    while(Q.size() > 2) {
        pii now = Q.top(); Q.pop();
        int u, k; tie(k, u) = now;

        chk[u] = true;
        for(int v : g[u]) if(!chk[v]) {
            --deg[v];
            if(deg[v] == 1) Q.emplace(k + 1, v);
            else ans[Q.size()] = ans[Q.size()+1] + k;
        }
    }

    scanf("%d", &q);
    while(q--) {
        int x;
        scanf("%d", &x);
        if(x == 1) printf("0\n");
        else printf("%d\n", n - 1 - ans[x]);
    }

    return 0;
}