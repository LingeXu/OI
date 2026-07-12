#include <bits/stdc++.h>
using namespace std;
int n;
int puzzle[6][8];  
struct record {
    int x, y, op;
};
vector<record> ans;
bool eliminate() {
    bool has_change = false;
    queue< pair<int, int> > q;
    for(int i = 1; i <= 5; i++) {
        for(int j = 1; j <= 5; j++) {
            if(puzzle[i][j] != 0 && puzzle[i][j] == puzzle[i][j + 1] && puzzle[i][j] == puzzle[i][j + 2]) {
                has_change = true;
                q.push(make_pair(i, j));
                q.push(make_pair(i, j + 1));
                q.push(make_pair(i, j + 2));
            }
        }
    }
    for(int j = 1; j <= 7; j++) {
        for(int i = 1; i <= 3; i++) {
            if(puzzle[i][j] != 0 && puzzle[i][j] == puzzle[i + 1][j] && puzzle[i][j] == puzzle[i+2][j]) {
                has_change = true;
                q.push(make_pair(i, j));
                q.push(make_pair(i + 1, j));    
                q.push(make_pair(i + 2, j));
            }
        }
    }
    if(!has_change)
        return false;
    while(!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        puzzle[x][y] = 0;
    }
    return true;
}
void drop() {
    for(int i = 1; i <= 5; i++) {
        int now = 1;
        for(int j = 1; j <= 7; j++) 
            if(puzzle[i][j] != 0) 
                puzzle[i][now++] = puzzle[i][j];
        for(; now <= 7; now++) 
            puzzle[i][now] = 0;
    }
}
int count_blocks() {
    int cnt = 0;
    for(int i = 1; i <= 5; i++)
        for(int j = 1; j <= 7; j++)
            if(puzzle[i][j] != 0) cnt++;
    return cnt;
}
bool dfs(int step) {
    drop();
    while(eliminate())
        drop();
    if(count_blocks() == 0)
        return true;
    if(step == n)
        return false;
    int backup[6][8];
    memcpy(backup, puzzle, sizeof(puzzle));
    for(int i = 1; i <= 5; i++) {   
        for(int j = 1; j <= 7; j++) {  
            if(puzzle[i][j] == 0)
                continue;
            if(i < 5) {
                swap(puzzle[i][j], puzzle[i + 1][j]);
                if(dfs(step + 1)) {
                    ans.push_back({i, j, 1});
                    return true;
                }
                memcpy(puzzle, backup, sizeof(puzzle));
            }
            if(i > 1 && puzzle[i - 1][j] == 0) {
                swap(puzzle[i][j], puzzle[i - 1][j]);
                if(dfs(step + 1)) {
                    ans.push_back({i, j, -1});
                    return true;
                }
                memcpy(puzzle, backup, sizeof(puzzle));
            }
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= 5; i++) {
        int x, pos = 0;
        while(cin >> x && x != 0) 
            puzzle[i][++pos] = x;
    }
    if(dfs(0)) 
        for(int i = ans.size() - 1; i >= 0; i--) 
            cout << ans[i].x - 1 << " " << ans[i].y - 1 << " " << ans[i].op << '\n';
    else    cout << -1 << endl;
    return 0;
}