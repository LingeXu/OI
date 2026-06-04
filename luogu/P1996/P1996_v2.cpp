#include<iostream>
#include<queue>
using namespace std;
int n,m;
queue<int> q;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        q.push(i);
    int cnt=1;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        if(cnt==m){
            cout<<x<<" ";
            cnt=1;
        }
        else{
            q.push(x);
            cnt++;
        }
    }
    return 0;
}