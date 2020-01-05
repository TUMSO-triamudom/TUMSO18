#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_back
#define p emplace
#define ii pair<int,int>
#define ll long long
using namespace std;
const int INF=1e9;
ll tab[100005];
ll x[100005];
int dp[100005];
int main(){
    int n,m;
    cin>>n>>m;
    FOR(i,n){
        scanf("%d",&tab[i]);
        tab[i]-=m/2;
        if(i!=0)tab[i]+=tab[i-1];
    }
    int ans=-1;
    FOR(i,n){
        if(tab[i]<=0||tab[i]>tab[n-1])continue;
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(tab[i]>tab[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
            ans=max(ans,dp[i]);
        }
    }
    printf("%d",ans);
}
