#include<iostream>
#include<set>
#include<algorithm>
#define N 32770
#define INF 0x3f3f3f3f
using namespace std;
set<int> s;
int main(){
    int n,ans=0;
    cin>>n;
    int x;
    for(int i=1;i<=n;i++){
        cin>>x;
        if(i==1){
            ans+=x;
            s.insert(x);
            continue;
        }

        set<int>::iterator it;
        it=s.lower_bound(x);
        int min_diff=INF;
        if(it!=s.end())
            min_diff=min(min_diff,abs(x-*it));
        if(it!=s.begin())
            min_diff=min(min_diff,abs(x-*(--it)));
        ans+=min_diff;
        s.insert(x);
    }
    cout<<ans;
    return 0;
}