#include<iostream>
#include<vector>

#define N 100001

using namespace std;

vector<int,greater<int>> tracks;
bool vis[N]={0};

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;

        if(i==1){
            tracks.push_back(x);
            continue;
        }

        for(int j=0;j<tracks.size();j++){
            if(tracks[j]>=x){
                tracks[j]=x;
                vis[x]=true;
                break;
            }
        }

        if(!vis[x])
            tracks.push_back(x);
    }

    cout<<tracks.size();

    return 0;
}