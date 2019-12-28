#include <bits/stdc++.h>
#define pii pair<int ,int>

using namespace std;
const long long MOD = 98765431;

long long solve(int n){
    queue<pii> q;
    for(int i = 0 ; i < 3 ; i++){
        q.emplace(i , 1);
    }
    long long ans = 0;
    while(q.size()){
        int now = q.front().second;
        int bit = q.front().first;
        q.pop();
        if(now == n){
            ans++;
            continue;
        }
        for(int i = 0 ; i < 3 ; i++){
            if((bit & i) == 0){
                q.emplace(i , now + 1);
            }
        }
    }
    if(ans >= MOD)
        ans -= MOD;
    return ans;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        printf("%lld\n",solve(n));
    }
}