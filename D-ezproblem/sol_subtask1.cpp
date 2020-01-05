#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e6 + 5;
const long long MOD = 1e9 + 7;

long long dp[MXN][3];

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        long long a;
        scanf("%d %lld",&n ,&a);
        dp[0][0] = 0;
        dp[0][1] = 1;
        dp[0][2] = a;
        for(int i = 1 ; i <= n ; i++){
            dp[i][0] = (dp[i - 1][1] * dp[i - 1][1]) % MOD + (2 * dp[i - 1][0] * dp[i - 1][2]) % MOD;
            dp[i][1] = (2 * dp[i - 1][1] * dp[i - 1][2]) % MOD;
            dp[i][2] = a;
        }
        printf("%lld\n",(dp[n][0]) % MOD);
    }
}