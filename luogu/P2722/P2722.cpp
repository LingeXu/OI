#include<iostream>
#include<algorithm>
#include<cmath>
#define MAXm 10001
#define MAXn 10001
using namespace std;

int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    int p[MAXn],t[MAXn];
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&p[i],&t[i]);
    }

    int dp[MAXm]={0};

    for(int i=0;i<n;i++)
    {
        for(int j=t[i];j<=m;j++)
        {
            dp[j]=max(dp[j],dp[j-t[i]]+p[i]);
        }
    }

    printf("%d",dp[m]);
    return 0;
}