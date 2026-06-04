#include<iostream>
using namespace std;
void dfs(int k, int x, int y, int add_x, int add_y){
    if(k == 2){
        if(x == 1 && y == 1)
            cout << 2 + add_x << ' ' << 2 + add_y << ' ' << 1 << '\n';
        else if(x == 1 && y == 2)
            cout << 2 + add_x << ' ' << 1 + add_y << ' ' << 2 << '\n';
        else if(x == 2 && y == 1)
            cout << 1 + add_x << ' ' << 2 + add_y << ' ' << 3 << '\n';
        else    cout << 1 + add_x << ' ' << 1 + add_y << ' ' << 4 << '\n';
        return;
    }
    int next = k >> 1;
    if(x <= next && y <= next){
        cout << next + 1 + add_x << ' ' << next + 1 + add_y << ' ' << 1 << '\n';
        dfs(next, x, y, add_x, add_y);
        dfs(next, next, 1, add_x, add_y + next);
        dfs(next, 1, next, add_x + next, add_y);
        dfs(next, 1, 1, add_x + next, add_y + next);
    }
    else if(x <= next && y > next){
        cout << next + 1 + add_x << ' ' << next + add_y << ' ' << 2 << '\n';
        dfs(next, x, y - next, add_x, add_y + next);
        dfs(next, next, next, add_x, add_y);
        dfs(next, 1, next, add_x + next, add_y);
        dfs(next, 1, 1, add_x + next, add_y + next);
    }
    else if(x > next && y <= next){
        cout << next + add_x << ' ' << next + 1 + add_y << ' ' << 3 << '\n';
        dfs(next, x - next, y, add_x + next, add_y);
        dfs(next, next, next, add_x, add_y);
        dfs(next, next, 1, add_x, add_y + next);
        dfs(next, 1, 1, add_x + next, add_y + next);
    }
    else{
        cout << next + add_x << ' ' << next +add_y << ' ' << 4 << '\n';
        dfs(next, x - next, y - next, add_x + next, add_y + next);
        dfs(next, next, next, add_x, add_y);
        dfs(next, next, 1, add_x, add_y + next);
        dfs(next, 1, next, add_x + next, add_y);
    }

}
int main(){
    int k, x, y;
    cin >> k >> x >> y;
    dfs((1 << k), x, y, 0, 0);
    return 0;
}