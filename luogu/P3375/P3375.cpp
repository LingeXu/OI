#include<iostream>

using namespace std;

vector<int> GetNext(const string &pat){
    int l=pat.size();
    vector<int> next(l+1);
    next[0]=-1;
    int i=0,j=-1;
    while(i<l){
        if(j==-1||pat[i]==pat[j])
            next[++i]=++j;
        else
            j=next[j];
    }
    return next;
}

void KMP(const string &ob,const string &pat){
    vector<int> next=GetNext(pat);
    int i=0,j=0;
    while(i<ob.size()){
        if(j==-1||ob[i]==pat[j]){
            i++;
            j++;
        }
        else
            j=next[j];
        if(j==pat.size()){
            cout<<i-j+1<<'\n';
            j=next[j];
        }
    }
    for(int i=1;i<=pat.size();i++)
        cout<<next[i]<<" ";
}

int main(){
    string ob,pat;
    cin>>ob;
    cin.ignore();
    cin>>pat;
    KMP(ob,pat);
    return 0;
}