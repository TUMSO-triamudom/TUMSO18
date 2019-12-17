#include <bits/stdc++.h>

using namespace std;
const long long MOD = 1e9 + 7;

long long ans , ans2;

void solve(long long n , long long a){
    if(n <= 0)return;
    solve(n >> 1 , a);
    ans *= ans;
    ans %= MOD;
    if(n & 1)ans *= a;
    ans %= MOD;
    return;
}

int main(){
    int t;
    scanf("%d" ,&t);
    while(t--){
        long long n , a;
        scanf("%lld %lld",&n ,&a);
        a *= 2;
        if(n == 0){
            printf("0\n");
            continue;
        }
        ans = 1;
        solve(n - 1 , a);
        ans2 = ((ans * ans) % MOD * a) % MOD - ans;
        ans = 1;
        if(ans2 < 0)ans2 += MOD;
        solve(MOD - 2 , a - 1);
        printf("%lld\n",(ans * ans2) % MOD);
    }
}