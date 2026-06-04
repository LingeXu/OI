#define LOCAL
#ifdef LOCAL
#define debug(x) cout<<'['<<__LINE__<<']'<<" "<<#x<<" = "<<x<<'\n';
#else
#define debug(x)
#endif
#include<iostream>
#include<algorithm>
#include<iomanip>
#define N 210
#define eps 1e-9
using namespace std;
int n,m;

struct flavour{
    int v,c;
    double val,weight;
}f[N];

bool cmp1(flavour a,flavour b){
    return a.val<b.val;
}

bool cmp2(flavour a,flavour b){
    return a.weight>b.weight;
}

bool check(double x){
    for(int i=0;i<n;i++)    f[i].weight=f[i].v-x*f[i].c;
    sort(f,f+n,cmp2);
    double sum=0;
    for(int i=0;i<m;i++)
        sum+=f[i].weight;
    if(sum>=0)  return 1;
    return 0;
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++)    cin>>f[i].v;
    for(int i=0;i<n;i++)    cin>>f[i].c;
    for(int i=0;i<n;i++)    f[i].val=1.0*f[i].v/f[i].c;
    sort(f,f+n,cmp1);
    double left=f[0].val,right=f[n-1].val;
    double ans;
    while(right-left>=eps){
        double mid=(left+right)/2;
        if(check(mid)){
            ans=mid;
            left=mid+eps;
        }
        else
            right=mid;
    }
    cout<<fixed<<setprecision(3)<<ans;
    return 0;
}