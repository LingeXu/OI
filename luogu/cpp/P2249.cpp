#include<iostream>

#define N 1000001
#define M 100001

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    int a[N],b[M];

    for(int i=0;i<n;i++)
        cin>>a[i];

    for(int i=0;i<m;i++)
    {
        cin>>b[i];
        int head=0,tail=n-1,mid;

        while(head<tail){
            mid=(head+tail)/2;
            if(a[mid]>=b[i])
                tail=mid;
            
            else 
                head=mid+1;
        }

        if(a[head]!=b[i])   cout<<-1<<" ";

        else    cout<<head+1<<" ";
    }

    return 0;
}