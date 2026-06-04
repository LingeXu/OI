#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

#define N 1001
#define M 1001
#define INF 0x3f3f3f3f

using namespace std;

int n,m;
int dist[2*(N-1)*(M-1)+2];

vector<pair<int,int> > graph[2*(N-1)*(M-1)+2];

void dijkstra(int s){
    memset(dist,0x3f,sizeof(dist));
    dist[s]=0;

    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;

    pq.push({0,s});

    while(!pq.empty()){
        int now=pq.top().second;
        int d=pq.top().first;
        pq.pop();

        if(d>dist[now]) continue;

        for(auto &e:graph[now])
        {
            if(dist[e.second]>dist[now]+e.first)
            {
                dist[e.second]=dist[now]+e.first;
                pq.push({dist[e.second],e.second});
            }
        }
    }
}

int main(){
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m-1;j++)
        {
            int x;
            cin>>x;

            if(i>=2&&i<=n-1)
            {
                graph[(i-2)*2*(m-1)+2*j-1].push_back({x,(i-1)*2*(m-1)+2*j});
                graph[(i-1)*2*(m-1)+2*j].push_back({x,(i-2)*2*(m-1)+2*j-1});
            }

            else if(i==1)
            {
                graph[2*(n-1)*(m-1)+1].push_back({x,2*j});
                graph[2*j].push_back({x,2*(n-1)*(m-1)+1});
            }

            else
            {
                graph[0].push_back({x,2*(n-2)*(m-1)+2*j-1});
                graph[2*(n-2)*(m-1)+2*j-1].push_back({x,0});
            }
        }
    }

    for(int i=1;i<=n-1;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int x;
            cin>>x;

            if(j>=2&&j<=m-1)
            {
                graph[(i-1)*2*(m-1)+2*(j-1)].push_back({x,(i-1)*2*(m-1)+2*(j-1)+1});
                graph[(i-1)*2*(m-1)+2*(j-1)+1].push_back({x,(i-1)*2*(m-1)+2*(j-1)});
            }

            else if(j==1)
            {
                graph[0].push_back({x,(i-1)*2*(m-1)+2*j-1});
                graph[(i-1)*2*(m-1)+2*j-1].push_back({x,0});
            }

            else
            {
                graph[2*i*(m-1)].push_back({x,2*(n-1)*(m-1)+1});
                graph[2*(n-1)*(m-1)+1].push_back({x,2*i*(m-1)});
            }
        }
    }

    for(int i=1;i<=n-1;i++)
    {
        for(int j=1;j<=m-1;j++)
        {
            int x;
            cin>>x;

            graph[(i-1)*2*(m-1)+2*j-1].push_back({x,(i-1)*2*(m-1)+2*j});
            graph[(i-1)*2*(m-1)+2*j].push_back({x,(i-1)*2*(m-1)+2*j-1});
        }
    }

    /*for(int i=0;i<=2*(n-1)*(m-1)+1;i++)
    {
        for(int j=0;j<graph[i].size();j++)
        {
            cout<<i<<" "<<graph[i][j].second<<" "<<graph[i][j].first<<endl;
        }
    }*/

    dijkstra(0);

    cout<<dist[2*(n-1)*(m-1)+1]<<endl;

    return 0;
}