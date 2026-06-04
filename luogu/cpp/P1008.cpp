#include<iostream>
using namespace std;

int main(){
    for(int i=123;i<=329;i++)
    {
        int a=i,b=2*i,c=3*i;
        int v[9]={0};
        v[a%10-1]=v[a/10%10-1]=v[a/100-1]=1;
        v[b%10-1]=v[b/10%10-1]=v[b/100-1]=1;
        v[c%10-1]=v[c/10%10-1]=v[c/100-1]=1;
        int sum=0;
        for(int j=0;j<9;j++)
        {
            sum+=v[j];
        }
        if(sum==9)
        {
            printf("%d %d %d\n",a,b,c);
        }
    }

    return 0;
}