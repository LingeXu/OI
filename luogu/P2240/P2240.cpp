#include<iostream>
#include<algorithm>

#define N 110

using namespace std;

struct gold{
    int m,v;
    double w;
}g[N];

bool cmp(gold x,gold y){
    return x.w>y.w;
}

int main(){
    int n,t;
    cin>>n>>t;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;

        g[i].m=a,g[i].v=b;
        g[i].w=1.0*b/a;
    }

    sort(g,g+n,cmp);

    /*for(int i=0;i<n;i++)
        cout<<g[i].w<<" ";*/

    int remain=t,now=0;
    double ans=0;
    while(remain>0&&now<n){
        int this_time=min(remain,g[now].m);
        //cout<<this_time<<'\n';
        ans+=this_time*g[now].w;
        remain-=this_time;
        //cout<<remain<<" "<<ans<<'\n';
        now++;
        //cout<<now<<'\n';
    }

    printf("%.2f",ans);
    return 0;
}