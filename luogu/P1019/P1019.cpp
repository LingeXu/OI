#include<iostream>
#include<vector>
#define N 25
using namespace std;
int ans = 0;
string word[N];
int remain[N];
vector<int> start;
vector< pair<int, int> > graph[N];
void dfs(int u, int now){
    ans = max(ans, now);
    for(auto &neighbor : graph[u]){
        if(--remain[neighbor.second] >= 0){
            dfs(neighbor.second, now + word[neighbor.second].size() - neighbor.first);
            remain[neighbor.second]++;
        }
    }
}
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> word[i];
    char c;
    cin >> c;
    for(int i = 1; i <= n; i++)
        if(word[i][0] == c)
            start.push_back(i);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int Length = min(word[i].size(), word[j].size());
            for(int k = 1; k <= Length; k--)
                if(word[i].substr(word[i].size() - k) == word[j].substr(0, k)){
                    graph[i].push_back({k, j});
                    break;
                }
        }
    }
    /*for(int i = 1; i <= n; i++)
        for(int j = 0; j < graph[i].size(); j++)
            cout << word[i] << ' ' << word[graph[i][j].second] << graph[i][j].first << '\n';*/
    for(auto it = start.begin(); it != start.end(); it++){
        for(int i = 1; i <= n; i++)
            remain[i] = 2;
        remain[*it] = 1;
        dfs(*it, word[*it].size());
    }
    cout << ans;
    return 0;
}