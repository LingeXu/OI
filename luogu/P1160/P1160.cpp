#include<iostream>
#include<list>
#define N 100010
using namespace std;
int n,m;
list<int> s;
list<int>::iterator pos[N];
int main(){
    cin>>n;
    s.push_back(1);
    pos[1]=s.begin();
    for(int i=2;i<=n;i++){
        int k,p;
        cin>>k>>p;
        list<int>::iterator it;
        it=pos[k];
        if(p==0)
            pos[i]=s.insert(it,i);
        else
            pos[i]=s.insert(++it,i);
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        int x;  
        cin>>x;
        if(pos[x]!=s.end()){
            s.erase(pos[x]);
            pos[x]=s.end();
        }
    }
    for(auto it=s.begin();it!=s.end();++it)
        cout<<*it<<" ";
    return 0;
}