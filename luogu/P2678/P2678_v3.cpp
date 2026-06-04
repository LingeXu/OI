#include<iostream>
#include<algorithm>

#define N 50001

using namespace std;

int l,n,m,ans;
int d[N];

bool check(int x){
    int cnt=0;
    int last=0;

    for(int i=0;i<=n;i++)
    {
        /*while(i<n&&d[i]-last<x)
        {
            cnt++;
            i++;
        }*/

        if(d[i]-last<x)
            cnt++;
        
        else    last=d[i];
    }

    /*if(l-last<x)
        return 0;*/

    return cnt<=m;
}

int main(){
    cin>>l>>n>>m;
    for(int i=0;i<n;i++)    cin>>d[i];
    
    d[n]=l;

    int head=0,tail=l,mid,ans;

    while(head<=tail){
        mid=(head+tail)/2;

        if(check(mid))
        {
            ans=mid;
            head=mid+1;
        }

        else
            tail=mid-1;
    }

    cout<<ans;

    return 0;
}