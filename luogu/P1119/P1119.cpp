#include<iostream>
#include<vector>
#include<queue>

#define N 201
#define M 19901
#define Q 50001
#define INF 0x3f3f3f3f

using namespace std;

vector<pair<int,int> > graph[N];

int t[N],dist[N];
bool inq[N];

void floyd(int u,int v,int d){
    memset(dist,0x3f,sizeof(dist));
    dist[u]=0;
    queue<int> joint_to_update;
    memset(inq,0,sizeof(inq));
    joint_to_update.push(u);
    inq[u]=true;

    while(!joint_to_update.empty()){
        int x=joint_to_update.front();
        joint_to_update.pop();
        inq[x]=false;

        for(auto &edge:graph[x])
        {
            if(t[x]>d||t[edge.second]>d)   continue;

            else
            {
                if(dist[edge.second]>dist[x]+edge.first)
                {
                    dist[edge.second]=dist[x]+edge.first;
                    if(!inq[edge.second])
                    {
                        joint_to_update.push(edge.second);
                    }
                }
            }
        }
    }
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);

    for(int i=0;i<n;i++)    scanf("%d",&t[i]);

    for(int i=0;i<m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);

        graph[u].push_back({w,v});
        graph[v].push_back({w,u});
    }

    int q;
    scanf("%d",&q);

    for(int i=1;i<=q;i++)
    {
        int x,y,t;
        scanf("%d%d%d",&x,&y,&t);

        floyd(x,y,t);

        if(dist[y]!=INF)    printf("%d\n",dist[y]);
        else    printf("-1\n");
    }

    return 0;
}