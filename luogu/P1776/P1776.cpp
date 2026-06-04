#include<iostream>
#include<algorithm>
#include<cmath>
#define MAXW 40001
using namespace std;

int main(){
    int n,W;
    scanf("%d %d",&n,&W);
    int dp[MAXW]={0};

    for(int i=0;i<n;i++)
    {
        int v,w,m;
        scanf("%d %d %d",&v,&w,&m);
        int cnt=1;
        int remain=m;
        while(remain>0)
        {
            int use=min(remain,cnt);
            int value=use*v;
            int weight=use*w;
            for(int j=W;j>=weight;j--)
            {
                dp[j]=max(dp[j],dp[j-weight]+value);
            }
            cnt*=2;
            remain-=use;
        }
    }

    printf("%d",dp[W]);
    return 0;
}