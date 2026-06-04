#include<iostream>

#define N 1001

using namespace std;

int main(){
    int n;
    cin>>n;

    int t[N];

    for(int i=0;i<n;i++)    cin>>t[i];

    int a[N];
    for(int i=0;i<n;i++)    a[i]=t[i];
    sort(t,t+n);

    int sum=0;

    for(int i=0;i<n;i++)  
    {
        sum+=t[i]*(n-i-1);
    }

    double ans=(double)sum/n;

    int j=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==t[j])
        {
            cout<<i+1<<" ";
            j++;
            i=-1;
        }
    }

    cout<<endl;
    printf("%.2f\n",ans);

    return 0;
}