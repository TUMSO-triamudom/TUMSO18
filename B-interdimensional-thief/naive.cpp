#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define fi first
#define se second
#define pb push_back
#define sz size
#define mp make_pair
#define all(x) (x).begin(), (x).end()

int visited[2005][2005], m, n, xs,ys;
ii grid[2005][2005], par[2005][2005];

void bfs(){
	queue<pair<ii, int> > q ;  
	for(int i = 1; i <= n; i++){
		q.push(mp(ii(i,1), 1));
		q.push(mp(ii(i,m), 1));
	}
	for(int i = 1; i<=m;i++){
		q.push(mp(ii(n,i), 1));
		q.push(mp(ii(1,i), 1));

	}
	while(!q.empty()){
		pair<ii,int> cur = q.front();
		int x = cur.fi.fi, y = cur.fi.se, len = cur.se;
		q.pop();
		if(visited[x][y]) continue;
		visited[x][y] = len;
		if(grid[x][y].fi == -1){
			int dx = x + y, dy = x - y + 2000, r = grid[x][y].se, nx,ny;
			for(int i = 0; i <= r;i++){
				nx = x + i; ny = y + r - i;
				if(nx > 0 && nx <= n && ny > 0 && ny <= m) 
					q.push(mp(ii(nx,ny), len + 1));
				nx = x + i; ny = y - r + i;
				if(nx > 0 && nx <= n && ny > 0 && ny <= m) 
					q.push(mp(ii(nx,ny), len + 1));
				nx = x - i; ny = y + r - i;
				if(nx > 0 && nx <= n && ny > 0 && ny <= m) 
					q.push(mp(ii(nx,ny), len + 1));
				nx = x - i; ny = y - r + i;
				if(nx > 0 && nx <= n && ny > 0 && ny <= m) 
					q.push(mp(ii(nx,ny), len + 1));
			}
		}else {
			q.push(mp(grid[x][y], len + 1));
		}
		
	}
}

int main(){
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	scanf("%d%d%d%d",&n,&m,&xs,&ys);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <=m; j++){
			int tmp; 
			scanf("%d", &tmp);
			if(tmp > 0) grid[i][j] = ii(tmp/m, tmp%m + 1);
			else grid[i][j] = ii(-1, -tmp);
		}
	}
	// for(int i = 1; i <= n;i++) {
	// 	for(int j = 1; j <= m;j++) printf("%d:%d ", grid[i][j].fi, grid[i][j].se);
	// 	cout << endl;
	// }
	bfs();
	printf("%d\n", visited[xs][ys] ? visited[xs][ys] : -1);

	
	return 0 ;
}