#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#define N 30001
#define M 26

using namespace std;

struct stuff{
    int space,value;
}a[M];

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&a[i].space,&a[i].value);
    }

    int dp[M][N];
    memset(dp,0,sizeof(dp));

    for(int i=0;i<=n;i++)
    {
        if(i>=a[0].space)
        {
            dp[0][i]=a[0].space*a[0].value;
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(a[i].space>j)
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-a[i].space]+a[i].space*a[i].value);
            }
            
        }
    }

    printf("%d",dp[m-1][n]);
    return 0;
}