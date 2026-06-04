#include<iostream>
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
    int len=1;

    for(int i=0;i<n;i++)
    {
        int MAX=a[i];
        int dp1[N];
        int len1=0;
        dp1[0]=0;
        for(int j=0;j<i;j++)
        {
            if(a[j]>dp1[len1]&&a[j]<MAX)
            {
                dp1[len1++]=a[j];
            }
            else
            {
                int head=0,tail=len1-1;
                while(head<tail)
                {
                    int mid=(head+tail)/2;
                    if(dp1[mid]>a[j])
                    {
                        tail=mid-1;
                    }
                    else
                    {
                        head=mid;
                    }   
                }
                dp1[head]=a[j];
            }
        }

        int dp2[N];
        int len2=0;
        dp2[0]=MAX;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<=dp2[len2]&&a[j]<MAX)
            {
                dp2[len2++]=a[j];
            }
            else
            {
                int head=0,tail=len2-1;
                while(head<tail)
                {
                    int mid=(head+tail)/2;
                    if(dp2[mid]<a[j])
                    {
                        tail=mid-1;
                    }
                    else
                    {
                        head=mid;
                    }   
                }
                dp2[head]=a[j];
            }
        }

        len=max(len1+len2+1,len);

    }

    printf("%d",n-len);

    return 0;
}