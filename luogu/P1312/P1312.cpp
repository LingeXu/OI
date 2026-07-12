#include <bits/stdc++.h>
using namespace std;
int n;
int puzzle[6][8];  
struct record {
    int x, y, op;
};
vector<record> ans;
bitset<35> exist;
bool eliminate() {
    bool has_change = false;
    for(int i = 1; i <= 5; i++) {
        for(int j = 1; j <= 5; j++) {
            if(puzzle[i][j] != 0 && puzzle[i][j] == puzzle[i][j + 1] && puzzle[i][j] == puzzle[i][j + 2]) {
                has_change = true;
                exist.reset((i - 1) * 7 + j);
                exist.reset((i - 1) * 7 + j + 1);
                exist.reset((i - 1) * 7 + j + 2);
            }
        }
    }
    for(int j = 1; j <= 7; j++) {
        for(int i = 1; i <= 3; i++) {
            if(puzzle[i][j] != 0 && puzzle[i][j] == puzzle[i + 1][j] && puzzle[i][j] == puzzle[i+2][j]) {
                has_change = true;
                exist.reset((i - 1) * 7 + j);
                exist.reset(i * 7 + j);
                exist.reset((i + 1) * 7 + j);
            }
        }
    }
    if(!has_change)
        return false;
    for(int i = 1; i <= 5; i++) 
        for(int j = 1; j <= 8; j++) 
            if(!exist.test((i - 1) * 7 + j)) 
                puzzle[i][j] = 0;
    return true;
}
void drop() {
    for(int i = 1; i <= 5; i++) {
        int now = 1;
        for(int j = 1; j <= 7; j++) {
            if(puzzle[i][j] != 0) {
                puzzle[i][now++] = puzzle[i][j];
                exist.set((i - 1) * 7 + now - 1);
                exist.reset((i - 1) * 7 + j);
            }
        }
        for(; now <= 7; now++) {
            puzzle[i][now] = 0;
            exist.reset((i - 1) * 7 + now);
        }
    }
}
bool dfs(int step) {
    if(step > n)
        return false;
    drop();
    while(eliminate())
        drop();
    if(!exist.any())    return true;
    for(int j = 1; j <= 7; j++) {      
        for(int i = 1; i <= 5; i++) {  
            if(puzzle[i][j] == 0)
                continue;
            if(i < 5) {
                swap(puzzle[i][j], puzzle[i + 1][j]);
                if(dfs(step + 1)) {
                    ans.push_back({i, j, 1});
                    return true;
                }
                else    swap(puzzle[i][j], puzzle[i + 1][j]);
            }
            if(i > 1) {
                swap(puzzle[i][j], puzzle[i - 1][j]);
                if(dfs(step + 1)) {
                    ans.push_back({i, j, -1});
                    return true;
                }
                else    swap(puzzle[i][j], puzzle[i - 1][j]);
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
        while(cin >> x && x != 0) {
            puzzle[i][++pos] = x;
            exist.set((i - 1) * 7 + pos);
        }
    }
    if(dfs(0)) 
        for(auto& r : ans) 
            cout << r.x - 1 << " " << r.y - 1 << " " << r.op << '\n';
    else    cout << -1 << endl;
    return 0;
}