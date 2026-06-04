#define LOCAL
#ifdef LOCAL
#define debug(x)    cout<<"["<<__LINE__<<"]"<<#x<<" "<<" = "<<x<<'\n';
#else
#define debug(x)
#endif
#include<iostream>
#include<queue>
#include<set>
using namespace std;
int n;
struct vessel{
    int time;
    set<int> country;
};
queue<vessel> q;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int t,k;
        cin>>t>>k;
        set<int> c;
        for(int j=1;j<=k;j++){
            int x;
            cin>>x;
            c.insert(x);
        }
        q.push({t,c});

        //debug(q.size());

        while(1){
            if(q.empty())
                break;
            vessel x=q.front();
            if(t-x.time>=86400)
                q.pop();
            else
                break;
            
        }
        queue<vessel> copy;
        set<int> s;
        while(!q.empty()){
            vessel x=q.front();
            q.pop();
            //cout<<"截至此处无bug！"<<'\n';
            s.insert(x.country.begin(),x.country.end());
            copy.push(x);
        }
        cout<<s.size()<<'\n';
        while(!copy.empty()){
            vessel x=copy.front();
            copy.pop();
            q.push(x);
        }
    }
    return 0;
}