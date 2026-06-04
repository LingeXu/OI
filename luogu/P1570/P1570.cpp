#define LOCAL
#ifdef LOCAL
#define debug(x) cout<<'['<<__LINE__<<']'<<" "<<#x<<" = "<<x<<'\n';
#else
#define debug(x)
#endif
#include<iostream>
#define N 210
using namespace std;
struct coffee{
    int v,c;
    double val;
}co[N];

bool cmp(coffee x,coffee y){
    return x.val>y.val;
}

int main(){
    int n,m;
    cin>>n>>m;
    int v,c;
    for(int i=0;i<n;i++){
        cin>>v;
        co[i].v=v;
    }
    for(int i=0;i<n;i++){
        cin>>c;
        co[i].c=c;
    }
    for(int i=0;i<n;i++){
        co[i].val=1.0*co[i].v/co[i].c;
    }

    sort(co,co+n,cmp);

    /*for(int i=0;i<n;i++){
        cout<<co[i].v<<" "<<co[i].c<<" "<<co[i].val<<'\n';
    }*/

    int v_sum=0,c_sum=0;
    for(int i=0;i<m;i++){
        v_sum+=co[i].v;
        c_sum+=co[i].c;
    }

    double ans=1.0*v_sum/c_sum;
    printf("%.3f",ans);
    return 0;
}