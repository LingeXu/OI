#include<iostream>
#include<algorithm>
#define N 100001
using namespace std;

int main(){
    int i=0;
    int a[N];
    while(scanf("%d",&a[i])!=EOF)
    {
        i++;
    }

    int dp[N];
    dp[0]=a[0];
    int len=1;
    for(int j=1;j<i;j++)
    {
        if(a[j]<=dp[len-1])
        {
            dp[len]=a[j];
            len++;
        }
        else
        {
            int head=0,tail=len-1,mid=(head+tail)/2;
            while(head<tail)
            {
                if(dp[mid]>=a[j])
                {
                    head=mid+1;
                }
                else
                {
                    tail=mid;
                }
                mid=(head+tail)/2;
            }
            dp[mid]=a[j];
        }
    }

    printf("%d\n",len);

    int dp2[N];
    dp2[0]=a[0];
    int len2=1;
    for(int j=1;j<i;j++)
    {
        if(a[j]>dp2[len2-1])
        {
            dp2[len2]=a[j];
            len2++;
        }
        else
        {
            int head=0,tail=len2-1,mid=(head+tail)/2;
            while(head<tail)
            {
                if(dp2[mid]<a[j])
                {
                    head=mid+1;
                }
                else
                {
                    tail=mid;
                }
                mid=(head+tail)/2;
            }
            dp2[mid]=a[j];
        }
    }

    printf("%d\n",len2);
    return 0;
}