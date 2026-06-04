#include<iostream>
#include<vector>
using namespace std;
vector< pair<int, int> > team, winner;
int main(){
    int n;
    cin >> n;
    int tot = (1 << n);
    for(int i = 1; i <= tot; i++){
        int x;
        cin >> x;
        team.push_back(make_pair(x, i));
    }
    while(1){
        winner.clear();
        for(int i = 0; i < team.size(); i += 2){
            if(team[i].first > team[i + 1].first)
                winner.push_back(team[i]);
            else if(team[i].first < team[i + 1].first)
                winner.push_back(team[i + 1]);
        }
        if(winner.size() == 1)
            break;
        team = winner;
    }
    if(team[0].first != winner[0].first)
        cout << team[0].second;
    else    cout <<team[1].second;
    return 0;
}