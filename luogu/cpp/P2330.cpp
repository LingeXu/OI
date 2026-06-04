#include<iostream>
#include<algorithm>

#define N 301

using namespace std;

struct edge{
    int u,v,w;
}e[N];

bool cmp(edge p,edge q){
    return p.w<q.w;
}

int fa[N];

int find(int x){
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);

    for(int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);

        e[i].u=a;
        e[i].v=b;
        e[i].w=c;
    }

    sort(e,e+m,cmp);

    for(int i=1;i<=n;i++)   fa[i]=i;

    int cnt1=0,cnt2=0;
    while(cnt1<n-1&&cnt2<m){
        if(find(e[cnt2].u)!=find(e[cnt2].v))
        {
            fa[find(e[cnt2].v)]=find(e[cnt2].u);
            cnt1++;
        }

        cnt2++;
    }

    printf("%d %d",n-1,e[cnt2-1].w);

    return 0;
}