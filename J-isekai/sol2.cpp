#include <bits/stdc++.h>
using namespace std;
const int X = 2e5 + 5;
int N, M, P, Q;
long long sm;
int le[X], dmg[X], h[X], hp[X], an[X];
bool mk[X];
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> M >> P >> Q;
	for(int i = 0; i < N; ++i) cin >> le[i];
	for(int i = 2; i <= M + 1; ++i) cin >> dmg[i];
	for(int i = 0; i < P; ++i) cin >> h[i];
	for(int i = 0; i < Q; ++i) cin >> hp[i];
	for(int cr = 0; cr < P; ++cr){
		for(int i = 0; i < N; ++i) if(le[i] >= h[cr]) mk[i] = 1;
		for(int i = 0, ct = 0; i <= N; ++i) if(mk[i]) ++ct; else sm += dmg[ct], ct = 0;
		for(int i = 0; i < Q; ++i) if(!an[i] && hp[i] <= sm) an[i] = cr + 1;
	}
	for(int i = 0; i < Q; ++i) cout << (an[i]? an[i] : -1) << ' ';
}
// Brute Force