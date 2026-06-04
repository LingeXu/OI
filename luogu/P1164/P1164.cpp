#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#define M 10001
#define N 101

using namespace std;

int main(){
    int n,m;
    scanf("%d %d",&n,&m);

    int a[N];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }


    int dp[N][M];

    memset(dp,0,sizeof(dp));

    dp[0][a[0]]=1;
    for(int i=0;i<n;i++)
    {
        dp[i][0]=1;
    }
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(a[i]>j)
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                dp[i][j]=dp[i-1][j]+dp[i-1][j-a[i]];
                
            }
        }
    }

    printf("%d",dp[n-1][m]);

    return 0;
}