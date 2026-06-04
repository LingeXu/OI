#include<iostream>
#define N 10001
#define INF 0x3f3f3f3f

using namespace std;

int dp[N][N];

int main(){
    int n;
    scanf("%d",&n);

    int a[N];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    
    memset(dp,0x3f,sizeof(dp));

    for(int i=0;i<n;i++)
        dp[i][i]=0;

    for(int len=2;len<=n;len++)
    {
        for(int i=0;i<=n-len;i++)
        {
            int sum=0;
            for(int j=i;j<=i+len-1;j++)
            {
                sum+=a[j];
            }

            for(int j=i;j<i+len-1;j++)
            {
                dp[i][i+len-1]=min(dp[i][i+len-1],dp[i][j]+dp[j+1][i+len-1]+sum);
            }

        }
        
            
    }

    printf("%d",dp[0][n-1]);

    return 0;
}