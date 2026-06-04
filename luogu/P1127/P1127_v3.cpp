#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#define N 1010
using namespace std;
int n;
int in_deg[26],out_deg[26],deg[26];
struct edge{
    int to;
    string word;
    bool vis;
};
vector<edge> graph[26];
vector<string> ans;
void InDegCnt(){
    for(int i=0;i<26;i++)
        for(int j=0;j<graph[i].size();j++)
            in_deg[graph[i][j].to]++;
}
void OutDegCnt(){
    for(int i=0;i<26;i++)
        out_deg[i]=graph[i].size();
}
void DegCnt(){
    for(int i=0;i<26;i++)
        deg[i]=in_deg[i]-out_deg[i];
}
int judge(){
    if(count(deg,deg+26,0)==26)
        return 0;
    else if(count(deg,deg+26,0)==24&&count(deg,deg+26,1)==1&&count(deg,deg+26,-1)==1)
        return 1;
    return 2;
}
bool cmp(edge x,edge y){
    return x.word<y.word;
}
void SortWord(){
    for(int i=0;i<26;i++)
        sort(graph[i].begin(),graph[i].end(),cmp);
}
void dfs(int u,int v){
    /*if(ans.size()==n)
        return;*/
    for(int i=0;i<graph[u].size();i++){
        if(!graph[u][i].vis){
            graph[u][i].vis=true;
            dfs(graph[u][i].to,v);
            ans.push_back(graph[u][i].word);
        }
    }
}
void output(){
    if(ans.size()!=n){
        cout<<"***";
        return;
    }//反例:a-b,c-d,d-e,e-c
    for(int i=n-1;i>=0;i--){
        cout<<ans[i];
        if(i!=0)
            cout<<'.';
    }
}
int main(){
    cin>>n;
    string s;
    int m=n;
    while(m>0){
        cin>>s;
        char begin=s[0],end=s.back();
        graph[begin-'a'].push_back({end-'a',s,false});
        m--;
    }
    InDegCnt();
    OutDegCnt();
    DegCnt();
    SortWord();
    if(judge()==2){
        cout<<"***";
        return 0;
    }
    else if(judge()==0){
        int start,end;
        for(int i=0;i<26;i++){
            if(in_deg[i]!=0){
                start=end=i;
                break;
            }
        }
        dfs(start,end);
        output();
    }
    else if(judge()==1){
        int start,end;
        for(int i=0;i<26;i++){
            if(deg[i]==-1)
                start=i;
            if(deg[i]==1)
                end=i;
        }    
        dfs(start,end);
        output(); 
    }
    return 0;
}