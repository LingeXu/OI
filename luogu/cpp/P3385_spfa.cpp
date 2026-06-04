#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

#define N 2001
#define INF 0x3f3f3f3f

using namespace std;

int dist[N],cnt[N];
bool inq[N];

vector<pair<int,int> > graph[N];

bool spfa(int n){
    memset(dist,0x3f,sizeof(dist));
    memset(cnt,0,sizeof(cnt));
    memset(inq,0,sizeof(inq));
    dist[1]=0;
    
    queue<int> q;
    q.push(1);
    inq[1]=true;

    while(!q.empty()){
        int x=q.front();
        q.pop();
        inq[x]=false;

        for(auto &edge:graph[x])
        {
            if(dist[x]!=INF&&dist[edge.second]>dist[x]+edge.first)
            {
                dist[edge.second]=dist[x]+edge.first;
                if(++cnt[edge.second]>=n)   return true;

                if(!inq[edge.second]) 
                {
                    q.push(edge.second);
                    inq[edge.second]=true;
                }
            }
        }
    }

    return false;
}

int main(){
    int t;
    scanf("%d",&t);

    while(t>0){
        int n,m;
        scanf("%d%d",&n,&m);

        for (int i=1;i<=N-1;i++) graph[i].clear();

        for(int i=1;i<=m;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);

            graph[u].push_back(make_pair(w,v));
            if (w>=0) graph[v].push_back(make_pair(w,u));
        }

        if(spfa(n)) printf("YES\n");
        else    printf("NO\n");

        t--;
    }

    return 0;
}