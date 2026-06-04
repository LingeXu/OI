#include<iostream>
#include<algorithm>
#define N 200001

using namespace std;

int main(){
    int n;
    scanf("%d",&n);

    int a[N],b[N];

    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&a[i],&b[i]);
    }
    



    int dp[N];
    dp[0]=b[0];
    int len=1;

    for(int i=1;i<n;i++)
    {
        if(b[i]>dp[len-1])
        {
            dp[len++]=b[i];
        }
        else
        {
            int head=0,tail=len;
            while(head<tail)
            {
                int mid=(head+tail)/2;
                if(dp[mid]>b[i])
                {
                    tail=mid;
                }
                else
                {
                    head=mid+1;
                }
            }
            dp[head]=b[i];
        }
    }

    printf("%d",len);
    return 0;
}