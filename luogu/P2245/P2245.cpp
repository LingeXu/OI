#include<iostream>
#include<algorithm>

#define N 100001
#define M 300001

using namespace std;

struct edge{
    int u,v,w;
}e[M];

bool cmp(edge p,edge q){
    return p.w<q.w;
}

int fa[N];

int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
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

    int q;
    scanf("%d",&q);

    for(int i=0;i<q;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);

        for(int j=1;j<=n;j++)   fa[j]=j;

        int cnt1=0,cnt2=0;

        while(cnt1<m&&find(a)!=find(b)){
            if(find(e[cnt2].u)!=find(e[cnt2].v))
            {
                fa[find(e[cnt2].v)]=find(e[cnt2].u);
                cnt2++;
            }
            cnt1++;
        }

        printf("%d\n",e[cnt2-1].w);


    }

    return 0;
}