#include<iostream>
#include<vector>
#include<algorithm>

#define N 5001
#define M 200001

using namespace std;

int n,m;

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

void kruskal(){
    int sum=0;

    sort(e,e+m,cmp);

    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
    }

    int ans=0;

    int cnt=n;
    
    while(ans<m){
        /*if(group[e[ans].u]!=group[e[ans].v])
        {
            group[e[ans].v]=group[e[ans].u];
            sum+=e[ans].w;
            cnt--;
        }*/

        if(find(e[ans].u)!=find(e[ans].v))
        {
            fa[find(e[ans].v)]=find(e[ans].u);
            sum+=e[ans].w;
            cnt--;
        }

        ans++;
    }

    if(cnt==1)  printf("%d",sum);
    else    printf("orz");
}

int main(){
    scanf("%d%d",&n,&m);

    for(int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);

        e[i]={a,b,c};
    }

    kruskal();

    return 0;
}