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
set<ii > d1[4005], d2[4005]; // d1 = up-left -> down-right, d2 = up-right -> down-left


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
	set<ii>::iterator itr, prev;
	while(!q.empty()){
		pair<ii,int> cur = q.front();
		int x = cur.fi.fi, y = cur.fi.se, len = cur.se;
		q.pop();
		if(visited[x][y]) continue;
		visited[x][y] = len;
		if(grid[x][y].fi == -1){
			int dx = x + y, dy = x - y + 2000, r = grid[x][y].se, nx,ny;
			if(dx - r > 0){
				itr = d2[dx - r].lower_bound(ii(x - r, 0));
				while(itr != d2[dx - r].end()){
					if((*itr).fi > x) break;
					//deal 
					q.push(mp(*itr, len + 1));
					prev = itr++;
					d2[dx - r].erase(prev);
				}
			}
			if(dx + r <= 4000){
				itr = d2[dx + r].lower_bound(ii(x, 0));
				while(itr != d2[dx + r].end()){
					if((*itr).fi > x + r) break;
					//deal 
					q.push(mp(*itr, len + 1));
					prev = itr++;
					d2[dx + r].erase(prev);
				}
			}
			if(dy - r >= 0){
				itr = d1[dy - r].lower_bound(ii(x - r, 0));	
				while(itr != d1[dy - r].end()){
					if((*itr).fi > x) break;
					//deal 
					
					q.push(mp(*itr, len + 1));
					
					prev = itr++;
					d1[dy - r].erase(prev);
				}			
			}
			if(dy + r <= 4000){
				itr = d1[dy + r].lower_bound(ii(x, 0));
				while(itr != d1[dy + r].end()){
					if((*itr).fi > x + r) break;
					//deal 
					
					q.push(mp(*itr, len + 1));
					
					prev = itr++;
					d1[dy + r].erase(prev);
				}	
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
			d1[i - j + 2000].insert(ii(i,j));
			d2[i + j].insert(ii(i,j));
		}
	}
	// for(int i = 1; i <= n;i++) {
	// 	for(int j = 1; j <= m;j++) printf("%d:%d ", grid[i][j].fi, grid[i][j].se);
	// 	cout << endl;
	// }
	bfs();
	printf("%d\n", visited[xs][ys] ? visited[xs][ys] : -1);
	// for(int i = 0; i <= 4000;i++){
	// 	if(d1[i].size() == 0)continue;		
	// 	for(auto x: d1[i]){
	// 		printf("(%d %d) ", x.fi, x.se);
	// 	}
	// 	cout << endl;
	// }
	// if(visited[xs][ys]){
	// 	ii cur = ii(xs,ys);
	// 	while(cur.fi != 1 && cur.fi != n && cur.se != 1 && cur.se != m){
	// 		printf("%d %d\n", cur.fi,cur.se);
	// 		cur = par[cur.fi][cur.se];
	// 	}
	// 	printf("%d %d\n", cur.fi,cur.se);
	// }
	return 0 ;
}