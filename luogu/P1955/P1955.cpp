#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<cstring>
#define N 100010
using namespace std;
int fa[2 * N];
struct edge{
    int a, b, e;
};
vector<edge> in;
vector<int> id;
vector< pair<int, int> > NotEqual;
int get_id(int x){
    return lower_bound(id.begin(), id.end(), x) - id.begin() + 1;
}
int find(int x){
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void unite(int x, int y){
    int rx = find(x), ry =find(y);
    if(rx != ry)    fa[rx] = ry;
}
int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        in.clear();
        id.clear();
        NotEqual.clear();
        int n;
        cin >> n;
        /*memset(fa, 0, sizeof(fa));
        for(int k = 1; k <= 2*N; k++)
            fa[k] = k;
        for(int j = 1; j <= n; j++){
            int a, b, e;
            cin >> a >> b >> e;
            if(e == 0)
                NotEqual.push_back(make_pair(a, b));
            else if(e == 1)
                unite(a, b);
        }*/
        for(int j = 1; j <= n; j++){
            int a, b, e;
            cin >> a >> b >> e;
            id.push_back(a);
            id.push_back(b);
            edge ed;
            ed.a = a;
            ed.b = b;
            ed.e = e;
            in.push_back(ed); 
        }
        sort(id.begin(), id.end());
        auto it = unique(id.begin(), id.end());
        id.erase(it, id.end());
        memset(fa, 0, sizeof(fa));
        for(int i = 1; i <= id.size(); i++)
            fa[i] = i;
        for(auto &ed : in){
            if(ed.e == 0)
                NotEqual.push_back(make_pair(get_id(ed.a), get_id(ed.b)));
            else if(ed.e == 1)
                unite(get_id(ed.a), get_id(ed.b));
        }
        bool ans = true;
        for(auto it = NotEqual.begin(); it != NotEqual.end(); it++){
    
            /*cout << it->first << ' ' << it->second << '\n';
            cout << fa[1] << ' ' << fa[2] << ' ' << fa[3] << ' ' << fa[4];*/
            if(find(it->first) == find(it->second)){
                ans = false;
                break;
            }
        }
        cout << (ans == true ? "YES" : "NO") << '\n';
    }
    return 0;
}