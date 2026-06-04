#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

#define N 201
#define T 21

using namespace std;

vector<int> graph[N];

int ans;
int head[N];
int match[N];
bool vis[N];

/*void dfs(int start){
    for(int &neighbor:graph[start])
    {
        if(!match[neighbor]&&!vis[neighbor])    
        {
            match[neighbor]=start;
            ans++;
        }

        else
        {
            vis[neighbor]=true;
            match[neighbor]=start;
            dfs(match[neighbor]);   
        }

        break;
    }
}*/

bool dfs(int start){
    for(int &neighbor:graph[start])
    {
        if(!vis[neighbor])
        {
            vis[neighbor]=true;

            if(!match[neighbor]||dfs(match[neighbor]))
            {
                match[neighbor]=start;
                return true;
            }
        }
    }

    return false;
}

int main(){
    int t;
    scanf("%d",&t);

    while(t>0){
        int n;
        scanf("%d",&n);
        
        for(int i=1;i<=n;i++)   graph[i].clear();

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                int a;
                scanf("%d",&a);

                if(a==1)   
                    graph[i].push_back(j);
            }
        }

        ans=0;
        memset(match,0,sizeof(match));

        for(int i=1;i<=n;i++)
        {
            memset(vis,0,sizeof(vis));
            
            if(dfs(i))
                ans++;
        }

        if(ans==n)  printf("Yes\n");
        else    printf("No\n");

        t--;
    }

    return 0;
}