#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>

#define N 10001

using namespace std;

int main(){
    int n;
    scanf("%d",&n);

    int a[N];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    sort(a,a+n);

    int sum=0,len=n;
    while(len>=2)
    {
        a[0]=a[0]+a[1];
        for(int i=1;i<len-1;i++)
            a[i]=a[i+1];
        sum+=a[0];
        sort(a,a+len-1);
    }
    
    printf("%d",sum);
    return 0;
}