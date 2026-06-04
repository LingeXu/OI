#include<iostream>
#include<algorithm>

#define N 1000001

using namespace std;

struct mat{
    int beg,ed;
}m[N];

bool cmp(mat x,mat y){
    return x.ed<y.ed;
}

int main(){
    int n;
    cin>>n;

    for(int i=0;i<n;i++)    cin>>m[i].beg>>m[i].ed;

    sort(m,m+n,cmp);

    int ans=0,last=0;

    for(int i=0;i<n;i++)
    {
        if(m[i].beg>=last)
        {
            last=m[i].ed;
            ans++;
        }
    }

    cout<<ans<<endl;

    return 0;
}