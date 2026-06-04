#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,node=0;
int dist[27];
bool has_node[27];
vector<int> g[27],in_deg(27,0);
bool cmp(int a,int b){
    return a>b;
}
bool Kahn(vector<int> in){
    int cnt=0;
    memset(dist,-1,sizeof(dist));
    queue<int> q;
    for(int i=1;i<=26;i++){
        if(has_node[i]==true&&in[i]==0){
            q.push(i);
            //cout<<i<<'\n';
            cnt++;
            dist[i]=0;
        }
    }
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int neighbor:g[x]){
            if(dist[x]!=-1)
                dist[neighbor]=max(dist[neighbor],dist[x]+1);
            if(--in[neighbor]==0){
                q.push(neighbor);
                //cout<<neighbor<<'\n';
                cnt++;
            }
        }
    }
    //cout<<cnt<<'\n';
    if(cnt==node)
        return false;
    else
        return true;
}
int main(){
    cin>>n>>m;
    string s;
    memset(has_node,0,sizeof(has_node));
    for(int i=1;i<=m;i++){
        cin>>s;
        g[s[0]-'A'+1].push_back(s.back()-'A'+1);
        in_deg[s.back()-'A'+1]++;
        if(has_node[s[0]-'A'+1]==false){
            has_node[s[0]-'A'+1]=true;
            node++;
        }
        if(has_node[s.back()-'A'+1]==false){
            has_node[s.back()-'A'+1]=true;
            node++;
        }

        /*cout<<node<<'\n';
        for(int i=1;i<=26;i++)
            cout<<has_node[i]<<" ";
        cout<<'\n';
        for(int i=1;i<=26;i++)
            cout<<in_deg[i]<<" ";
        cout<<'\n';*/

        if(Kahn(in_deg)){
            printf("Inconsistency found after %d relations.",i);
            return 0;
        }
        int maxdist=0;
        for(int i=1;i<=26;i++)
            if(dist[i]>maxdist)
                maxdist=dist[i];
        if(maxdist==n-1){
            printf("Sorted sequence determined after %d relations: ",i);
            int now=0;
            for(int i=1;i<=26;i++){
                if(now<=maxdist&&dist[i]==now){
                    cout<<(char)('A'+i-1);
                    now++;
                    i=0;
                    //continue;
                }
            }
            cout<<".";
            return 0;
        }
    }
    cout<<"Sorted sequence cannot be determined.";
    return 0;
}