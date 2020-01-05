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
int s1,s2;
int q1[100005];
int q2[100005];
int qs1(int pos){
    return q1[pos]-q1[s1];
}
int qs2(int pos){
    return q2[pos]-q2[s2];
}
int query(int a,int b,int c,int d,int k){
    //printf("%d %d %d %d %d\n",a,b,c,d,k);
    int m1=(b-a)/2;
    int m2=(d-c)/2;
    if(a==b)return qs2(c+k-1);
    if(c==d)return qs1(a+k-1);
    if(m1+m2+2<=k){
        if(qs1(a+m1)<qs2(c+m2))return query(a+m1+1,b,c,d,k-m1-1);
        else return query(a,b,c+m2+1,d,k-m2-1);
    }
    else {
        if(qs1(a+m1)<qs2(c+m2))return query(a,b,c,c+m2,k);
        return query(a,a+m1,c,d,k);
    }
}
int main(){
    int n,m,q;
    cin>>n>>m>>q;
    FOR1(i,n)scanf("%d",&q1[i]),q1[i]+=q1[i-1];
    FOR1(i,m)scanf("%d",&q2[i]),q2[i]+=q2[i-1];
    while(q--){
        int a,b,c,d,k;
        scanf("%d %d %d %d %d",&a,&c,&b,&d,&k);
        s1=a-1;
        s2=c-1;
        int x=query(a,b+1,c,d+1,k);
        printf("%d\n",x);
    }
}
