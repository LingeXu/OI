#include<iostream>
#include<vector>
#include<queue>

#define N 100001

using namespace std;

int n,m;
vector<int> graph[N];
bool visited[N];

void dfs(int u){
    visited[u]=true;

    printf("%d ",u);

    for(int i=0;i<graph[u].size();i++)
    {
        if(!visited[graph[u][i]])
            dfs(graph[u][i]);
    }
}

void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u]=true;

    while(!q.empty()){
        printf("%d ",q.front());

        for(int i=0;i<graph[q.front()].size();i++)
        {
            
            if(!visited[graph[q.front()][i]])
            {
                visited[graph[q.front()][i]]=true;
                q.push(graph[q.front()][i]);
            }
        }
        q.pop();
    }


}

int main(){
    scanf("%d%d",&n,&m);


    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        graph[a].push_back(b);
    }

    for(int i=1;i<=n;i++)
    {
        sort(graph[i].begin(),graph[i].end());
    }

    dfs(1);

    printf("\n");
    
    memset(visited,0,sizeof(visited));

    bfs(1);

    return 0;


}