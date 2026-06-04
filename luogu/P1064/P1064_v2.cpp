#include<iostream>
#include<vector>
#include<cmath>

#define N 32001
#define M 61

using namespace std;

struct item{
    int v,p,q;
    vector<int> g;
}a[M];

bool cmp(item x,item y){
    return x.q<y.q;
}

int dp[M][N];

int main(){
    int n,m;
    scanf("%d%d",&n,&m);

    
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&a[i].v,&a[i].p,&a[i].q);  
        
    }

    for(int i=0;i<m;i++)
    {
        if(a[i].q!=0)   a[a[i].q-1].g.push_back(i);
    }
   // sort(a,a+m,cmp);

    /*for(int i=0;i<m;i++)
    {
        if(a[i].q!=0)   a[a[i].q-1].g.push_back(i);
    }*/

    memset(dp,0,sizeof(dp));

    for(int i=0;i<m;i++)
    {
        
        if(a[i].q!=0)   continue;

        if(i>=1)
        {
            for(int j=0;j<=n;j++)
                dp[i][j]=dp[i-1][j];
        }

        vector<pair<int,int>> plans;

        plans.push_back({a[i].v,a[i].v*a[i].p});
        if(a[i].g.size()>=1)    plans.push_back({a[i].v+a[a[i].g[0]].v,a[i].v*a[i].p+a[a[i].g[0]].v*a[a[i].g[0]].p});   
        if(a[i].g.size()>=2)    
        {
            plans.push_back({a[i].v+a[a[i].g[1]].v,a[i].v*a[i].p+a[a[i].g[1]].v*a[a[i].g[1]].p});   
            plans.push_back({a[i].v+a[a[i].g[1]].v+a[a[i].g[0]].v,a[i].v*a[i].p+a[a[i].g[1]].v*a[a[i].g[1]].p+a[a[i].g[0]].v*a[a[i].g[0]].p});   

        }
       

        for(int k=plans.size()-1;k>=0;k--)
        {
            for(int j=n;j>=plans[k].first;j--)
            {
                dp[i][j]=max(dp[i][j],dp[i-1][j-plans[k].first]+plans[k].second);
            }
        }
    }

    printf("%d",dp[m-1][n]);
    return 0;

}