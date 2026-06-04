#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
map<int, priority_queue<int, vector<int>, greater<int> > > group;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> ab(n);
    for(int i = 0; i < n; i++)
        cin >> ab[i];
    sort(ab.begin(), ab.end());
    for(int x : ab){
        auto it = group.find(x - 1);
        if(it != group.end() && !it->second.empty()){
            int size = it->second.top();
            it->second.pop();
            group[x].push(size + 1);
        }
        else    group[x].push(1);
    }
    int ans = INF;
    for(auto& g : group)
        if(!g.second.empty())
            ans = min(ans, g.second.top());
    cout << ans;
    return 0;
}