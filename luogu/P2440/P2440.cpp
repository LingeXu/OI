#include<iostream>
#include<vector>

#define N 100010

using namespace std;

struct wood{
    int length,cnt;
}w[N];

bool cmp(wood x,wood y){
    return x.length>y.length;
}

int main(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        w[i].length=x;
    }

    sort(w,w+n,cmp);

    int left=1,right=w[0].length;
    //cout<<right<<'\n';
    int ans=-1;
    while(left<=right){
        int sum=0;
        int mid=(left+right)/2;
        for(int i=0;i<n;i++){
            w[i].cnt=w[i].length/mid;
            sum+=w[i].cnt;
        }
        //cout<<left<<" "<<right<<" "<<mid<<" "<<sum<<'\n';
        if(sum>=k){
            ans=mid;
            left=mid+1;
        }
        else if(sum<k){
            right=mid-1;
        }
    }

    if(ans!=-1)
        cout<<ans;
    else    cout<<0;

    return 0;
}