#include<iostream>
#include<algorithm>

#define N 1001
#define M 10001

using namespace std;

int fa[N];

struct edge{
    int u,v,w;
}e[M];

bool cmp(edge x,edge y){
    return x.w<y.w;
}

int find(int x){
    if(fa[x]==x)    return x;
    return find(fa[x]);
}
int main(){
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);

    for(int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);

        e[i]={a,b,c};
    }

    for(int i=1;i<=n;i++)   fa[i]=i;

    sort(e,e+m,cmp);

    int cnt1=0,cnt2=0,sum=0;

    while(cnt1<m&&cnt2<n-k){
        if(find(e[cnt1].u)!=find(e[cnt1].v))
        {
            fa[find(e[cnt1].v)]=find(e[cnt1].u);
            sum+=e[cnt1].w;
            cnt2++;
        }
        cnt1++;
    }

    if(cnt2<n-k) printf("No Answer");
    else printf("%d",sum);

    return 0;
}