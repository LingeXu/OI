#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<cstring>

#define N 20001
#define M 100001

using namespace std;

struct edge{
    int u,v,w;
}e[M];

bool cmp(edge x,edge y){
    return x.w>y.w;
}

int fa[N];
bool inq[M];

int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

queue<pair<pair<int,int>,int> > q;

int main(){
    int n,m;
    scanf("%d%d",&n,&m);


    for(int i=1;i<=n;i++)   fa[i]=i;

    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);

        e[i].u=a;
        e[i].v=b;
        e[i].w=c;
    }

    sort(e,e+m,cmp);

    int fx=e[0].u,fy=e[0].v;

    int cnt=0;
    for(int i=1;i<m;i++)
    {
        while(find(e[i].u)!=fx&&find(e[i].u)!=fy&&find(e[i].v)!=fx&&find(e[i].v)!=fy) 
        {
            if(!inq[i])
            {
                q.push({{e[i].u,e[i].v},e[i].w});
                inq[i]=true;
            }
            
            i++;
            cnt++;
        }
        
        if(find(e[i].u)==find(e[i].v))
        {
            printf("%d\n",e[i].w);
            break;
        }
        
        if(find(e[i].u)==fx&&find(e[i].v)!=fy)
        {
            fa[find(e[i].v)]=fy;
            if(!q.empty()&&e[i].v==q.front().first.first)
            {
                q.pop();
                i-=(cnt+1);
            }
        }
            
        if(find(e[i].u)==fy&&find(e[i].v)!=fx)
        {
            fa[find(e[i].v)]=fx;
            if(!q.empty()&&e[i].v==q.front().first.first)
            {
                q.pop();
                i-=(cnt+1);
            }
        }

        if(find(e[i].v)==fx&&find(e[i].u)!=fy)
        {
            fa[find(e[i].u)]=fy;
            if(!q.empty()&&e[i].u==q.front().first.first)
            {
                q.pop();
                i-=(cnt+1);
            }
        }

        if(find(e[i].v)==fy&&find(e[i].u)!=fx)
        {
            fa[find(e[i].u)]=fx;
            if(e[i].u==q.front().first.first)
            {
                q.pop();
                i-=(cnt+1);
            }
        }


        if((find(e[i].u)==fx&&find(e[i].v)==fy)||(find(e[i].u)==fy&&find(e[i].v)==fx))
            continue;

        cnt=0;
    }

    return 0;
}