#include <bits/stdc++.h>

using namespace std;
const long long MOD = 98765431;

long long temp[2][2] , ans[2][2] , l[2][2];

void mul1(){
    for(int i = 0 ; i < 2 ; i++){
        for(int j = 0 ; j < 2 ; j++){
            temp[i][j] = 0;
            for(int k = 0 ; k < 2 ; k++){
                temp[i][j] += ans[i][k] * ans[k][j];
                temp[i][j] %= MOD;
            }
        }
    }
    for(int i = 0 ; i < 2 ; i++){
        for(int j = 0 ; j < 2 ; j++){
            ans[i][j] = temp[i][j];
        }
    }
}

void mul2(){
    for(int i = 0 ; i < 2 ; i++){
        for(int j = 0 ; j < 2 ; j++){
            temp[i][j] = 0;
            for(int k = 0 ; k < 2 ; k++){
                temp[i][j] += ans[i][k] * l[k][j];
                temp[i][j] %= MOD;
            }
        }
    }
    for(int i = 0 ; i < 2 ; i++){
        for(int j = 0 ; j < 2 ; j++){
            ans[i][j] = temp[i][j];
        }
    }
}

void solve(long long now){
    if(now <= 1)return;
    solve(now >> 1);
    mul1();
    if(now & 1)mul2();
    return;
}

int main(){
    int t;
    long long n , p;
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&n);
        if(n == 1){
            printf("3\n");
            continue;
        }
        ans[0][0] = l[0][0] = 2;
        ans[0][1] = l[0][1] = 1;
        ans[1][0] = l[1][0] = 1;
        ans[1][1] = l[1][1] = 0;
        solve(n - 1);
        p = 3 * ans[0][0] + ans[0][1];
        printf("%lld\n" , p % MOD);
    }
}