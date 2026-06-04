#include<iostream>
#include<vector>
#include<cstring>
#define N 1010
using namespace std;
int n;
int leftchild[N], rightchild[N];
vector<int> price;
pair<int, int> inf[N];
pair<int, int> GetAns(int x){
    //cout << "GetAns(" << x << ")" << endl;
    if(inf[x].second)  return inf[x];
    if(leftchild[x] == -1 && rightchild[x] == -1)   return inf[x] = {price[x], 1};
    pair<int, int> Left = GetAns(leftchild[x]);
    pair<int, int> Right = GetAns(rightchild[x]);
    int leftval = Left.first;
    int rightval = Right.first;
    int val = min(price[x], leftval + rightval);
    int leftmethod = Left.second;
    int rightmethod = Right.second;
    if(price[x] < leftval + rightval)   return inf[x] = {val, 1};
    else if(price[x] > leftval + rightval)  return inf[x] = {val, leftmethod * rightmethod};
    else    return inf[x] = {val, leftmethod * rightmethod + 1};
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        price.push_back(x);
    }
    memset(leftchild, -1, sizeof(leftchild));
    memset(rightchild, -1, sizeof(rightchild));
    int a, b, c;
    while(cin >> a >> b >> c){
        leftchild[c] = a;
        rightchild[c] = b;
    }
    cout << GetAns(0).first << ' ' << GetAns(0).second;
    return 0;
}