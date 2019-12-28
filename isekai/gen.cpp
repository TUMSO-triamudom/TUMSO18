#include <bits/stdc++.h>
using namespace std;
del(){
	string str; cin >> str; str = "sub3/" + str;
	freopen(str.c_str(), "w", stdout);
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	del();
	mt19937 mt(time(0));
	uniform_int_distribution<> gt(1, 2e5), gt2(1, 2e9), gt3(1, 1e4);
	int N = 200000, M = 100000, P = 200000, Q = 200000;
	cout << N << ' ' << M << ' ' << P << ' ' << Q << '\n';
	for(int i = 0; i < N; ++i) cout << gt2(mt) << ' '; cout << '\n';
	for(int i = 2; i <= M + 1; ++i) cout << gt3(mt) << ' '; cout << '\n';
	for(int i = 0; i < P; ++i) cout << gt2(mt) << ' '; cout << '\n';
	for(int i = 0; i < Q; ++i) cout << gt2(mt) << ' '; cout << '\n';
}