#include<iostream>
#include<algorithm>
#define N 101
using namespace std;

int main(){
    int n;
    scanf("%d",&n);

    int a[N];

    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    int dp1[N],dp2[N];
    for(int i=0;i<n;i++)
    {
        dp1[i]=1;
        for(int j=0;j<i;j++)
        {
            if(a[j]<a[i])
            {
                dp1[i]=max(dp1[i],dp1[j]+1);
            }
        }
    }

    for(int i=n-1;i>=0;i--)
    {
        dp2[i]=1;
        for(int j=n-1;j>i;j--)
        {
            if(a[j]<a[i])
            {
                dp2[i]=max(dp2[i],dp2[j]+1);
            }
        }
    }
    int dp[N];
    int ans=0;
    for(int i=0;i<n;i++)
    {
        dp[i]=dp1[i]+dp2[i]-1;
        ans=max(ans,dp[i]);
    }

    printf("%d",n-ans);
}