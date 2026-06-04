#include<iostream>
#include<algorithm>

typedef long long ll;

#define N 1000001

using namespace std;

int n,m;
ll sum;
int h[N];
ll s[N];

int main(){
    cin>>n>>m;

    sum=0;

    for(int i=0;i<n;i++)   
    {
        cin>>h[i];
        sum+=h[i];
    } 

    ll rem=sum-m;

    if(rem<0)
    {
        cout<<0;
        return 0;
    }

    sort(h,h+n);

    s[0]=h[0]*n;
    for(int i=1;i<n;i++)    s[i]=s[i-1]+(h[i]-h[i-1])*(n-i);

    int head=0,tail=n-1;

    while(head<tail){
        int mid=(head+tail)/2;

        if(s[mid]>=rem)
            tail=mid;

        else    head=mid+1;
    }

    if(s[head]==rem)
        cout<<h[head];

    else if((s[head]-rem)%(n-head)!=0)
        cout<<h[head]-(s[head]-rem)/(n-head)-1;

    else
        cout<<h[head]-(s[head]-rem)/(n-head);

    return 0;
}