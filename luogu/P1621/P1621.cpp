#include<iostream>
#include<vector>
#define B 100010
using namespace std;
int fa[B];
bool IsNotPrime[B];
vector<int> prime;
vector<int> graph[B];
void euler(int n){
    for(int i = 2; i <= n; i++){
        if(!IsNotPrime[i])
            prime.push_back(i);
        for(int j = 0; j < prime.size() && i * prime[j] <= n; j++){
            IsNotPrime[i * prime[j]] = true;
            if(i % prime[j] == 0)
                break;
        }
    }
}
int find(int x){
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void unite(int x, int y, int &group){
    int rx = find(x), ry = find(y);
    if(rx != ry){
        fa[rx] = ry;
        group--;
    }
}
int main(){
    int a, b, p, group;
    cin >> a >> b >> p;
    group = b - a + 1;
    for(int i = a; i <= b; i++)
        fa[i] = i;
    euler(b);
    auto it = lower_bound(prime.begin(), prime.end(), p);
    prime.erase(prime.begin(), it);
    /*for(int i = 0; i < prime.size(); i++)
        cout << prime[i] << ' ';
    cout << '\n';*/
    //group += prime.size();
    /*for(int i = 0; i < prime.size(); i++){
        int gcd = prime[i];
        for(int j = a; j <= b; j++)
            if(j % gcd == 0)
                graph[gcd].push_back(j);
        for(int k = 0; k < graph[gcd].size(); k++)
            unite(gcd, graph[gcd][k], group);
    }*/
    for(int i = 0; i < prime.size(); i++){
        int gcd = prime[i];
        int start = ((a % gcd == 0) ? a : (a + gcd - a % gcd));
        if(!(start >= a && start <= b))
            continue;
        //cout << gcd << ' ' << start << '\n';
        int now = start;
        while(now + gcd >= a && now + gcd <= b){
            unite(start, now + gcd, group);
            now += gcd;
        }
    }
    cout << group;
    return 0;
}