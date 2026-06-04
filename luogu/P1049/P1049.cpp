#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define N 31
#define M 20001
using namespace std;

int main() {
    int V,n;
    scanf("%d",&V);
    scanf("%d",&n);
    int s[N];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&s[i]);
    }
    

    int dp[N][M];
    memset(dp,0,sizeof(dp));
    
    for(int i=0;i<=V;i++)
    {
        if(i>=s[0])
        {
            dp[0][i]=s[0];
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=V;j++)
        {
            if(j>=s[i])
            {
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-s[i]]+s[i]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    printf("%d",V-dp[n-1][V]);
    return 0;
}