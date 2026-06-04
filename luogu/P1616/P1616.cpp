#include<iostream>
#include<algorithm>
#include<cmath>
#define MAXT 10000001
#define MAXv 10001
#define MAXt 10001
using namespace std;

int main(){
    int T,M;
    scanf("%d %d",&T,&M);
    int v[MAXv],t[MAXt];
    for(int i=0;i<M;i++)
    {
        scanf("%d %d",&t[i],&v[i]);
    }

    int dp[MAXT]={0};
    for(int i=0;i<M;i++)
    {
        for(int j=t[i];j<=T;j++)
        {
            dp[j]=max(dp[j],dp[j-t[i]]+v[i]);
        }
    }

    printf("%d",dp[T]);
    return 0;
}