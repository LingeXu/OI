#include<iostream>
#include<algorithm>
#include<cmath>
#define MAXr 1001
using namespace std;

int main(){
    int r;
    scanf("%d",&r);
    int dp[MAXr][MAXr];
    for(int i=0;i<r;i++)
    {
        int a[MAXr];
        for(int j=0;j<i+1;j++)
        {
            scanf("%d",&a[j]);
            dp[i][j]=a[j];
        }
        if(i>0)
        {
            dp[i][0]+=dp[i-1][0];
            dp[i][i]+=dp[i-1][i-1];
        }
    }
    for(int i=2;i<r;i++)
    {
        for(int j=1;j<i;j++)
        {
            dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+dp[i][j];
        }
    }

    int ans=0;
    for(int i=0;i<r;i++)
    {
        if(dp[r-1][i]>=ans)
        {
            ans=dp[r-1][i];
        }
    }

    printf("%d",ans);
    return 0;
}