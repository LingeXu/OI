#include<iostream>
#include<cstring>

#define N 501
#define M 501
#define E 50001

using namespace std;

int n,m,e,cnt;

int head[N],match[M];
bool vis[M];

struct edge{
    int to,next;
}ed[E];

/*void hungary(int u){
    if(!match[ed[head[u]].to])
    {            
        match[ed[head[u]].to]=u;
        vis[ed[head[u]].to]
        cnt++;
        if(u<n) hungary(++u);
    }
        
    if(match[ed[head[u]].to]&&vis[ed[head[u]].to])
    {   
        int x=match[ed[head[u]].to];
        match[ed[head[u]].to]=u;
        hungary(x);
    }
}*/

bool hungary(int u){
    for(int i=head[u];i;i=ed[i].next)
    {
        if(vis[ed[i].to])   continue;


        if(!match[ed[i].to])
        {
            match[ed[i].to]=u;
            return true;
        }

        else
        {
            vis[ed[i].to]=true;
            
            if(hungary(match[ed[i].to]))
            {
                match[ed[i].to]=u;
                return true;
            }
            
        }
    }

    return false;
}

int main(){
    scanf("%d%d%d",&n,&m,&e);

    for(int i=1;i<=e;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);

        ed[i].to=b;
        ed[i].next=head[a];
        head[a]=i;
    }

    cnt=0;

    for(int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        if(hungary(i))
            cnt++;
    }

    printf("%d\n",cnt);

    return 0;
}