#include<iostream>
#include<algorithm>

#define N 10001
#define M 20001

using namespace std;

int n,m,s,t;

struct edge{
    int u,v,w;
}e[M];

bool cmp(edge x,edge y){
    return x.w<y.w;
}

int fa[N];

int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

int main(){
    scanf("%d%d%d%d",&n,&m,&s,&t);

    for(int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);

        e[i]={a,b,c};
    }

    sort(e,e+m,cmp);

    for(int i=1;i<=n;i++)   fa[i]=i;

    int ans=0;

    while(ans<m){
        if(find(e[ans].u)!=find(e[ans].v))
        {
            fa[find(e[ans].v)]=find(e[ans].u);

        }

        if(find(s)==find(t))
        {
            printf("%d\n",e[ans].w);
            break;
        }

        ans++;
    }

    return 0;
}