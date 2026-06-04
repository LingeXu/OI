#include<iostream>
#define N 1010
using namespace std;
int fa[N];
int find(int x){
    return fa[x] == x ? x : find(fa[x]);
}
void unite(int x, int y, int &tot){
    int rx = find(x), ry = find(y);
    if(rx != ry){
        fa[rx] = ry;
        tot--;
    }
}
int main(){
    int n, m;
    while(cin >> n && n != 0){
        cin >> m;
        for(int i = 1; i <= n; i++) 
            fa[i] = i;
        int tot = n;
        for(int i = 1; i <= m; i++){
            int a, b;
            cin >> a >> b;
            unite(a, b, tot);
        }
        cout << tot - 1 << '\n';
    }
    return 0;
}