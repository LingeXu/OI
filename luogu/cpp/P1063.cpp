#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#define E 201

using namespace std;

struct Node{
    int x,y;
}b[E];

int main(){
    int e;
    scanf("%d",&e);
    int a[E];
    for(int i=0;i<e;i++)
    {
        scanf("%d",&a[i]);
    }

    b[e-1].x=a[e-1];
    b[e-1].y=a[0];
    for(int i=0;i<e-1;i++)
    {
        b[i].x=a[i];
        b[i].y=a[i+1];
    }

    for(int i=0;i<e;i++)
    {
        b[i+e]=b[i];
    }

    int dp[E][E];
    dp[2*e-1][2*e-1]=0;
    for(int i=0;i<2*e-1;i++)
    {
        dp[i][i]=0;
       // dp[i][i+1]=b[i].x*b[i].y*b[i+1].y;
    }
    for(int i=0;i<2*e;i++)
    {
        for(int len=2;len<=e;len++)
        {
            for(int j=i;j<i+len-1;j++)
            {
                dp[i][i+len-1]=max(dp[i][i+len-1],dp[i][j]+dp[j+1][i+len-1]+b[i].x*b[j].y*b[i+len-1].y);
            }
        }
    }

    int ans=0;
    for(int i=0;i<e;i++)
    {
        ans=max(ans,dp[i][i+e-1]);
    }

    printf("%d",ans);
    return 0;
}