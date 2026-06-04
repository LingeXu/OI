#include<iostream>
#include<set>
#define N 10010
#define P 131
typedef unsigned long long ULL;
using namespace std;
int n;
ULL p[N],h[N];
set<ULL> hash_val;
void init(const string s){
    int l=s.size();
    p[0]=1;
    h[0]=0;
    for(int i=1;i<=l;i++){
        p[i]=p[i-1]*P;
        h[i]=h[i-1]*P+s[i-1];
    }
}

ULL get_hash(int l,int r){
    if(l>r)
        return -1;
    return h[r]-h[l-1]*p[r-l+1];
}

int main(){
    cin>>n;
    cin.ignore();
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        init(s);
        hash_val.insert(get_hash(1,s.size()));
    }
    cout<<hash_val.size();
    return 0;
}