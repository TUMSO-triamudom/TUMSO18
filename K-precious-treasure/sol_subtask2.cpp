#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e6 + 5;
const long long MOD = 98765431;

long long dp[2][4][4] , ans[MXN];

int main(){
    int t;
    scanf("%d",&t);
    for(int i = 0 ; i < 3 ; i++){
        dp[0][i][0] = 1;
        ans[1] += dp[0][i][0];
    }
    int now = 1 , prev = 0;
    for(int n = 2 ; n < MXN ; n++){
        for(int i = 0 ; i < 3 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                dp[now][i][j] = 0;
                if((i & j) == 0){
                    for(int k = 0 ; k < 3 ; k++){
                        if((j & k) == 0){
                            dp[now][i][j] += dp[prev][j][k];
                            if(dp[now][i][j] >= MOD)
                                dp[now][i][j] -= MOD;
                        }
                    }
                }
                ans[n] += dp[now][i][j];
                if(ans[n] >= MOD)
                    ans[n] -= MOD;
            }        
        }
        swap(now , prev);
    }
    while(t--){
        int n;
        scanf("%d",&n);
        printf("%lld\n",ans[n]);
    }
}