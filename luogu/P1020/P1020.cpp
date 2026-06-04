#include<iostream>
#define N 100001
using namespace std;

int main(){
    int a[N];
    int i=0;
    while(scanf("%d",&a[i])!=EOF)
    {
        i++;
    }

    int dp[N];
    for(int j=0;j<i;j++)
    {
        dp[j]=1;
    }

    for(int j=i-1;j>=0;j--)
    
    {
        for(int k=i-1;k>j;k--)
        {
            if(a[k]<=a[j])
            {
                dp[j]=max(dp[j],dp[k]+1);
            }
        }
    }

    int ans=0;
    for(int j=0;j<i;j++)
    {
        if(dp[j]>=ans)
        {
            ans=dp[j];
        }
    }

    printf("%d\n",ans);

    int dp2[N];
    for(int j=0;j<i;j++)
    {
        dp2[j]=1;
    }

    for(int j=0;j<i;j++)
    {
        for(int k=0;k<j;k++)
        {
            if(a[k]<a[j])
            {
                dp2[j]=max(dp2[k]+1,dp2[j]);
            }
        }
    }

    int ans2=0;
    for(int j=0;j<i;j++)
    {
        if(dp2[j]>=ans2)
        {
            ans2=dp2[j];
        }
    }

    printf("%d",ans2);
    return 0;
}