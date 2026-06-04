#include<iostream>
#include<vector>

#define N 201
#define M 5001
using namespace std;

vector<pair<int,int> > graph[N];

int dp[N];
bool vis[N];
int w[N][N];
int n,m,s,t;

void dfs(int start){
    for(auto &edge:graph[start])
    {
        if(!vis[edge.second])
        {
            dfs(edge.second);
        }
        dp[start]=min(dp[edge.second],edge.first)+w[start][t];
    }

    vis[start]=true;
}

int main(){
    scanf("%d%d%d%d",&n,&m,&s,&t);

    for(int i=1;i<=m;i++)
    {
        int from,to,weight;
        scanf("%d%d%d",&from,&to,&weight);

        graph[from].push_back({weight,to});

        w[from][to]=weight;
    }

    dfs(s);

    printf("%d\n",dp[s]);
    
    return 0;
}