#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
#define db(a) printf("<%d> ",a)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_back
#define p emplace
#define ii pair<int,int>
#define ll long long
#define rf() freopen("input.txt","r",stdin)
using namespace std;
const int INF=1e9;
int t1[100005];
int t2[100005];
int check(int a,int b,int c,int d,int k){
    int sum1=0,sum2=0;
    int p1=a,p2=c;
    int ans=-1;
    for(int i=0;i<k;i++){
        if(p1>b){
            sum2+=t2[p2];
            ans=sum2;
            p2++;
        }
        else if(p2>d){
            sum1+=t1[p1];
            ans=sum1;
            p1++;
        }
        else if(sum1+t1[p1]<sum2+t2[p2]){
                sum1+=t1[p1];
                ans=sum1;
                p1++;
            }
        else{
            sum2+=t2[p2];
            ans=sum2;
            p2++;
        }
    }
    return ans;
}
int main(){
    int n,m,q;
    cin>>n>>m>>q;
    FOR1(i,n)scanf("%d",&t1[i]);
    FOR1(i,m)scanf("%d",&t2[i]);
    while(q--){
        int a,b,c,d,k;
        scanf("%d %d %d %d %d",&a,&c,&b,&d,&k);
        int x=check(a,b,c,d,k);
        printf("%d\n",x);
    }
}
