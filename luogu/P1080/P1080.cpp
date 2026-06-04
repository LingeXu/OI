#include<iostream>
#include<vector>
#include<algorithm>
#define N 1010
using namespace std;
struct minister{
    int lefthand, righthand, result;
}m[N];
bool cmp(minister x, minister y){
    return x.result < y.result;
}
vector<int> leftans[N], finalans[N]; 
vector<int> TakeOffPreZeros(vector<int> a){
    int start = 0;
    while(a[start] == 0 && start < a.size() - 1)
        start++;
    vector<int> ans;
    for(int i = start; i < a.size(); i++)
        ans.push_back(a[i]);
    return ans;
}
vector<int> mul(vector<int> a, int b){
    vector<int> ans;
    int carry = 0;
    for(int i = 0; i < a.size() || carry != 0; i++){
        int now = (i < a.size() ? a[i] * b + carry : carry);
        ans.push_back(now % 10);
        carry = now / 10;
    }
    return ans;
}
vector<int> div(vector<int> a, int b){
    vector<int> ans;
    int last = 0;
    for(int i = a.size() - 1; i >= 0; i--){
        int now = last * 10 + a[i];
        while(now < b){
            ans.push_back(0);
            if(i == 0)
                return TakeOffPreZeros(ans);
            now = now * 10 + a[--i];
        }
        ans.push_back(now / b);
        last = now % b;
    }
    return TakeOffPreZeros(ans);
}
vector<int> compare(vector<int> a, vector<int> b){
    if(a.size() != b.size())
        return a.size() > b.size() ? a : b;
    for(int i = 0; i < a.size(); i++)
        if(a[i] != b[i])
            return a[i] > b[i] ? a : b;
    return a;
}
int main(){
    int n, a, b;
    cin >> n >> a >> b;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        m[i].lefthand = x;
        m[i].righthand = y;
        m[i].result = x * y;
    }
    sort(m, m + n, cmp);
    while(a != 0){
        leftans[0].push_back(a % 10);
        a /= 10;
    }
    finalans[0] = div(leftans[0], m[0].righthand);
    for(int i = 1; i < n; i++){
        leftans[i] = mul(leftans[i - 1], m[i - 1].lefthand);
        finalans[i] = div(leftans[i], m[i].righthand);
    }
    vector<int> maxcoin = finalans[0];
    for(int i = 1; i < n; i++)
        maxcoin = compare(maxcoin, finalans[i]);
    for(int i = 0; i < maxcoin.size(); i++)
        cout << maxcoin[i];
    return 0;
}