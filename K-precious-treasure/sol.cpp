#include <bits/stdc++.h>

using namespace std;
const long long MOD = 98765431;

long long temp[3][3] , ans[3][3] , l[3][3];

void mul1(){
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            temp[i][j] = 0;
            for(int k = 0 ; k < 3 ; k++){
                temp[i][j] += ans[i][k] * ans[k][j];
                temp[i][j] %= MOD;
            }
        }
    }
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            ans[i][j] = temp[i][j];
        }
    }
}

void mul2(){
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            temp[i][j] = 0;
            for(int k = 0 ; k < 3 ; k++){
                temp[i][j] += ans[i][k] * l[k][j];
                temp[i][j] %= MOD;
            }
        }
    }
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
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

void reset(){
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            if(i == 1 && j == 1){
                ans[i][j] = l[i][j] = 0;
            }else if(i == 2 && j == 2){
                ans[i][j] = l[i][j] = 0;
            }else{
                ans[i][j] = l[i][j] = 1;
            }
        }
    }
}

int main(){
    int t;
    long long n , p;
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&n);
        reset();
        solve(n + 1);
        p = ans[0][0];
        printf("%lld\n" , p % MOD);
    }
}