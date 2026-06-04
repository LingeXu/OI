#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<cstring>

#define N 56
#define INF 0x3f3f3f3f

using namespace std;

int n;
int level[2*N+2],iter[2*N+2],match[N];
bool has_in[N];

struct edge{
    int to,rev,cap;
};

vector<edge> graph[2*N+2],save[2*N+2];

bool is_square(int x){
    int r=sqrt(x);
    return r*r==x;
}

void add_edge(int a,int b,int c){
    graph[a].push_back({b,(int)graph[b].size(),c});
    graph[b].push_back({a,(int)graph[a].size()-1,0});
}

bool bfs(int s,int t){
    memset(level,-1,sizeof(level));
    level[s]=0;

    queue<int> q;
    q.push(s);

    while(!q.empty()){
        int x=q.front();
        q.pop();

        for(auto &e:graph[x])
        {
            if(e.cap>0&&level[e.to]==-1)
            {
                level[e.to]=level[x]+1;
                q.push(e.to);
            }
        }
    }

    return level[t]!=-1;
}

int dfs(int s,int t,int f){
    if(s==t)    return f;
    if(f==0)    return 0;

    for(int &i=iter[s];i<graph[s].size();i++)
    {
        edge &e=graph[s][i];
        if(e.cap>0&&level[e.to]==level[s]+1)
        {
            int d=dfs(e.to,t,min(f,e.cap));

            if(d>0)
            {
                e.cap-=d;
                graph[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }

    return 0;
}

int max_flow(int s,int t){
    int maxf=0;

    while(bfs(s,t)){
        memset(iter,0,sizeof(iter));

        int flow=dfs(s,t,INF);
        while(flow>0){
            maxf+=flow;
            flow=dfs(s,t,INF);
        }
    }

    return maxf;
}

int main(){
    cin>>n;

    /*int m=1;

    for(int i=1;i<=m;i++)
    {
        add_edge(0,i,1);

        for(int j=i;j<=m;j++)
        {
            add_edge(m+j,2*m+1,1);

            int x=sqrt(i+j);
            if(x*x==i+j)
                add_edge(i,m+j,1);
        }
    }*/

    /*for(int i=0;i<=2*n+1;i++)
    {
        for(int j=0;j<graph[i].size();j++)
        {
            cout<<i<<" "<<graph[i][j].to<<endl;
        }
    }*/

    //int m=0,flow=0;

    /*while(1){
        for(int i=0;i<=2*m+1;i++)
            graph[i]=save[i];

        m++;

        add_edge(0,m,1);
        add_edge(2*m,2*m+1,1);

        for(int i=1;i<=m;i++)
        {
            int x=sqrt(m+i);
            if(x*x==m+i)
                add_edge(i,2*m,1);
        }

        for(int i=0;i<=2*m+1;i++)
            save[i]=graph[i];

        if(m-max_flow(0,2*m+1)>n)
            break;
    }*/

    //m-=1;
    //cout<<m<<endl;

    /*while(m-max_flow(0,2*m+1)<=n){
        m++;

        for(int i=0;i<=2*m+1;i++)
            graph[i].clear();

        for(int i=1;i<=m;i++)
        {
            add_edge(0,i,1);

            for(int j=i;j<=m;j++)
            {
                add_edge(m+j,2*m+1,1);

                int x=sqrt(i+j);
                if(x*x==i+j)
                    add_edge(i,m+j,1);
            }
        }
    }*/

    /*for(int i=1;i<=m;i++)
    {
        for(int j=0;j<graph[i].size();j++)
        {
            edge &e=graph[i][j];

            if(e.cap==0&e.to!=0&&e.to!=2*m+1)
            {
                has_in[e.to-m]=true;
                match[i]=e.to-m;
            }
        }
    }*/


    /*for(int i=1;i<=m;i++)
    {
        int now=i;
        if(!has_in[now])
        {
            cout<<now<<" ";

            while(match[now]!=0){
                now=match[now];
                cout<<now<<" ";
            }

            cout<<endl;
        }
    }*/

    int now=0,flow=0;

    while(1){
        for(int i=0;i<=2*now+1;i++)
            graph[i]=save[i];

        now++;

        add_edge(0,now+1,1);
        add_edge(2*now+1,1,1);

        for(int i=2;i<=now+1;i++)
        {
            if(is_square(now+i-1))
                add_edge(i,2*now+1,1);
        }

        for(int i=0;i<=2*now+1;i++)
            save[i]=graph[i];

        if(now-max_flow(0,1)>n)
            break;
    }

    now-=1;
    cout<<now<<endl;

    for(int i=2;i<=2*now+1;i++)
    {
        for(int j=0;j<save[i].size();j++)
        {
            edge &e=save[i][j];

            if(e.to!=0&&e.to!=1)
                cout<<i-1<<" "<<e.to-1<<" "<<endl;
        }
    }

    /*for(int i=2;i<=now+1;i++)
    {
        for(int j=0;j<save[i].size();j++)
        {
            edge &e=save[i][j];

            if(e.cap==0&&e.to!=0)
            {
                match[i]=e.to-now;
                has_in[e.to-now]=true;
            }
        }
    }*/

    /*for(int i=2;i<=now+1;i++)
    {
        int here=i;
        if(!has_in[here])
        {
            cout<<here-1<<" ";

            while(match[here]!=0){
                here=match[here];
                cout<<here-1<<" ";
            }

            cout<<endl;
        }
    }*/

    return 0;
}