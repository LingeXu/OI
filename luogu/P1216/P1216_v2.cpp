#include<iostream>
#include<algorithm>
#define MAXr 1001
using namespace std;

int main(){
    int r;
    scanf("%d",&r);
    int dp[MAXr][MAXr];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<i+1;j++)
        {
            scanf("%d",&dp[i][j]);
        }
    }

    for(int i=r-2;i>=0;i--)
    {
        for(int j=0;j<i+1;j++)
        {
            dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+dp[i][j];
        }
    }
    printf("%d",dp[0][0]);
    return 0;
}