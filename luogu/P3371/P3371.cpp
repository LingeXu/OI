#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

#define N 10001

using namespace std;

vector<pair<int,int> > graph[N];

bool visit[N];

void bfs(int start){
    queue<int> visited;
    visit[start]=true;
    visited.push(start);
    while(!visited.empty()){
        for(auto &neighbours:graph[visited.front()])
        {
            if(!visit[neighbours.first])
                visit[neighbours.first]=true;
                visited.push(neighbours.first);
        }
        visited.pop();
        
    }
}


int main(){
    int n,m,s;
    scanf("%d%d%d",&n,&m,&s);

    for(int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);

        graph[a].push_back({b,c});
    }


    
}