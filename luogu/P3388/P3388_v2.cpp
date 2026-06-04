#include<iostream>
#include<vector>

#define N 20001

using namespace std;

int cnt,ans;
int dfn[N],low[N];
bool cut[N];

vector<int> graph[N];

void tarjan(int u,int root){
    dfn[u]=low[u]=++cnt;
    int child_cnt=0;

    for(int &to:graph[u])
    {
        if(!dfn[to])
        {
            child_cnt++;
            tarjan(to,root);
            low[u]=min(low[u],low[to]);
            if(u!=root&&low[to]>=dfn[u]) cut[u]=true;
        }

        else    low[u]=min(low[u],dfn[to]);
    }

    if(u==root&&child_cnt>=2)   cut[root]=true;
}

int main(){
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    cnt=0;
    ans=0;

    for(int i=1;i<=n;i++)
        if(!dfn[i])
            tarjan(i,i);

    for(int i=1;i<=n;i++)
        if(cut[i]==true)
            ans++;
    
    cout<<ans<<endl;
   
    for(int i=1;i<=n;i++)
        if(cut[i]==true)
            printf("%d ",i);

    return 0;
}