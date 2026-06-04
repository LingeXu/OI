#include<iostream>
#define MAXN (1 << 17) + 10
using namespace std;
int leftchild[MAXN], rightchild[MAXN];

void dfs_pre(int rt, int &k){
    if(k == 0)
        return;
    if(leftchild[rt] == 0 && rightchild[rt] == 0)
        return;
    if(leftchild[rt] > rightchild[rt]){
        swap(leftchild[rt], rightchild[rt]);
        k--;
    }
    dfs_pre(leftchild[rt], k);
    dfs_pre(rightchild[rt], k);
    return;
}

int dfs(int rt, int k){
    if(leftchild[rt] == 0 && rightchild[rt] == 0)
        return rt;
    if(k == 0)
        return dfs(leftchild[rt], k);
    return min(dfs(leftchild[rt], k), dfs(rightchild[rt], k - 1));
}

void dfs_other(int rt, int &k){
    if(k == 0)
        return;
    if(leftchild[rt] == 0 && rightchild[rt] == 0)
        return;
    int left_min = dfs(leftchild[rt], k);
    int right_min = dfs(rightchild[rt], k - 1);
    if(left_min > right_min){
        swap(leftchild[rt], rightchild[rt]);
        k--;
    }
    dfs_other(leftchild[rt], k);
    dfs_other(rightchild[rt], k);
    return;
}

void out(int rt, char c){
    if(rt == 0)
        return;
    if(c == 'A'){
        cout << rt << ' '; 
        out(leftchild[rt], c);
        out(rightchild[rt], c);
    }
    else if(c == 'B'){
        out(leftchild[rt], c);
        cout << rt << ' ';
        out(rightchild[rt], c);
    }
    else if(c == 'C'){
        out(leftchild[rt], c);
        out(rightchild[rt], c);
        cout << rt << ' ';
    }
    return;
}
int main(){
    char c;
    int n, root, k;
    cin >> c >> n >> root >> k;
    for(int i = 1; i <= n; i++){
        int l, r;
        cin >> l >> r;
        leftchild[i] = l;
        rightchild[i] = r;
    }
    if(c == 'A'){
        dfs_pre(root, k);
        out(root, c);
    }
    else{
        dfs_other(root, k);
        out(root, c);
    }
    return 0;
}