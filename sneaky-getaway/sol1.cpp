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
int main(){
    int n,m;
    cin>>n>>m;
    FOR(i,n){
        scanf("%d",&tab[i]);
        tab[i]-=m/2;
        if(i!=0)tab[i]+=tab[i-1];
    }
    int sz=0;
    for(int i=0;i<n;i++){
        if(tab[i]<=0||tab[i]>tab[n-1])continue;
        int ans=INF;
        if(sz==0)x[0]=tab[i],sz++;
        else if(tab[i]>x[sz-1])x[sz]=tab[i],sz++;
        else{
            int l=0,r=sz-1;
            while(l<=r){
                int m=(l+r)/2;
                if(tab[i]==x[m]){ans=-1;break;}
                else if(tab[i]<x[m])r=m-1,ans=m;
                else l=m+1;
            }
            if(ans!=-1)x[ans]=tab[i];
        }
    }
    printf("%d",sz);
}
