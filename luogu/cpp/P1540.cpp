#include<iostream>
#include<queue>
#include<cstring>
#define N 1010
using namespace std;
queue<int> q;
bool inq[N];
int main(){
    int m,n,cnt=0;
    cin>>m>>n;
    memset(inq,0,sizeof(inq));
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(inq[x])
            continue;
        else{
            cnt++;
            if(q.size()<m){
                q.push(x);
                inq[x]=true;
                //cout<<x<<" "<<cnt<<"\n";
            }
            else{
                int f=q.front();
                q.pop();
                inq[f]=false;
                
                q.push(x);
                inq[x]=true;   
                //cout<<f<<" "<<x<<" "<<cnt<<"\n";
            }
        }
    }
    cout<<cnt;
    return 0;
}