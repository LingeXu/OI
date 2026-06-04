#include<iostream>
#include<vector>
#include<queue>
#define N 1010
using namespace std;
int n;
int in_deg[N];
bool vis[N];
struct WordNode{
    char begin,end;
    string word;
}w[N];
vector<int> g[N];
vector<string> ans;
void Kahn(){
    for(int i=1;i<=n;i++)
        for(int j=0;j<g[i].size();j++)
            in_deg[g[i][j]]++;
    queue<int> q;
    string maxs="a";
    int start;
    for(int i=1;i<=n;i++){
        if(in_deg[i]==0){
            if(w[i].word>maxs){
                maxs=w[i].word;
                start=i;
            }
        }
    }
    q.push(start);
    vis[start]=true;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int neighbor:g[x]){
            if(--in_deg[neighbor]==0){
                q.push(neighbor);
                ans.push_back(w[neighbor].word);
                vis[neighbor]=true;
            }
        }
    }
}
int main(){
    cin>>n;
    string s;
    for(int i=1;i<=n;i++){
        cin>>s;
        w[i].begin=s[0];
        w[i].end=s[s.size()-1];
        w[i].word=s;
    }

    /*for(int i=1;i<=n;i++)
        cout<<w[i].begin<<" "<<w[i].end<<" "<<w[i].word<<'\n';*/

    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(w[i].begin==w[j].end){
                //cout<<"YES!"<<'\n';
                g[j].push_back(i);
            }
            if(w[i].end==w[j].begin){
                //cout<<"NO!"<<'\n';
                g[i].push_back(j);
            }
        }
    }
    Kahn();
    for(int i=1;i<=n;i++){
        if(vis[i]==false){
            cout<<i<<'\n';
            cout<<"***";
            //return 0;
        }
    }
    /*for(int i=1;i<=n;i++)
        for(int j=0;j<g[i].size();j++)
            cout<<i<<" "<<j<<" "<<w[i].word<<" "<<w[g[i][j]].word<<'\n';*/
    vector<int>::iterator it;
    for(auto it=ans.begin();it!=ans.end();++it)
        cout<<*it<<".";
    return 0;
}