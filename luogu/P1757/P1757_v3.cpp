#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>

#define M 1001
#define N 1001
#define K 101

using namespace std;

struct item{
    int w,v,p;
}a[N];

bool cmp(item x,item y){
    return x.p<y.p;
}

int main(){
    int m,n;
    scanf("%d%d",&m,&n);

    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d",&a[i].w,&a[i].v,&a[i].p);
    }

    sort(a,a+n,cmp);

    int dp[M],dp_old[M];
    memset(dp,0,sizeof(dp));
    memset(dp_old,0,sizeof(dp_old));

    for(int i=0;i<n;)
    {
        vector<pair<int,int>> team;
       /* for(int j=i;j<n;j++)
        {
            if(a[i].p==a[j].p)
            {
                team.push_back({a[j].w,a[j].v});
            }
        }
        */

        int j=i;
        while(j<n&&a[i].p==a[j].p)
        {
            team.push_back({a[j].w,a[j].v});
            j++;
        }

        for(auto &[w,v]:team)
        {
            for(int j=m;j>=w;j--)
            {
                dp[j]=max(dp[j],dp_old[j-w]+v);
            }
        }

        for(int j=0;j<=m;j++)
        {
            dp_old[j]=dp[j];
        }

        i=j;
    }

    printf("%d",dp[m]);
    return 0;
}