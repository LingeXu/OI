#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#define N 100010
using namespace std;
int main(){
    int q,n;
    cin>>q;
    while(q>0){
        cin>>n;
        int x;
        vector<int> in,out;
        stack<int> s;
        queue<int> qu;
        for(int i=0;i<n;i++){
            cin>>x;
            in.push_back(x);
        }
        int y;
        for(int i=0;i<n;i++){
            cin>>y;
            out.push_back(y);
        }
        for(int i=0;i<n;i++){
            s.push(in[i]);
            qu.push(out[i]);
            while(!s.empty()&&!qu.empty()&&s.top()==qu.front()){
                s.pop();
                qu.pop();
            }
        }
        if(s.empty()&&qu.empty())
            cout<<"Yes"<<'\n';
        else    cout<<"No"<<'\n';
        q--;
    }
    return 0;
}