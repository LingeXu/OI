#include<iostream>
#include<vector>
#include<queue>
#define N 100010
using namespace std;
int ans=0;
int cnt[N];
struct vessel{
    int time,size;
    //int country[N];
    vector<int> country;
};
queue<vessel> q;
int main(){
    int n;
    cin>>n;
    vessel v;
    for(int i=1;i<=n;i++){
        cin>>v.time>>v.size;
        while(!q.empty()){
            if(v.time-q.front().time>=86400){
                for(int j=0;j<q.front().size;j++)
                    if(--cnt[q.front().country[j]]==0)
                        ans--;
                q.pop();
            }
            else    break;
        }
        int x;
        for(int j=1;j<=v.size;j++){
            cin>>x;
            v.country.push_back(x);
            if(++cnt[x]==1)
                ans++;
        }
        q.push(v);
        cout<<ans<<'\n';
        v.country.clear();
    }
    return 0;
}