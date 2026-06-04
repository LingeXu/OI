#include<iostream>
#include<cstring>

#define N 1001
#define M 5001

using namespace std;

int fa[N];

int enemy[N];

int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

void unite(int x,int y){
    int rx=find(x),ry=find(y);
    
    if(rx!=ry)   
        fa[rx]=ry;
} 

bool cmp(int x,int y){
    return x>y;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);

    memset(enemy,0,sizeof(enemy));

    for(int i=1;i<=n;i++)   fa[i]=i;
    
    for(int i=1;i<=m;i++)
    {
        char c;
        int a,b;
        cin>>c>>a>>b;

        if(c=='F')  unite(a,b);

        if(c=='E')
        {
            if(enemy[a])    unite(enemy[a],b);
            else    enemy[a]=b;

            if(enemy[b])    unite(a,enemy[b]);
            else    enemy[b]=a;
        }
    }

    int ans=0;

    for(int i=1;i<=n;i++)
    {
        if(fa[i]==i)
            ans++;
    }

    printf("%d\n",ans);

    return 0;
}