#include<iostream>
#include<queue>
using namespace std;
priority_queue< int, vector<int>, less<int> > pq;
int main(){
    int l, n, k;
    cin >> l >> n >> k;
    int last = 0;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if(i != 1)
            pq.push(x - last);
        last = x;
    }
    for(int i = 1; i <= k; i++){
        int x = pq.top();
        pq.pop();
        pq.push(x / 2);
        pq.push(x - x / 2);
    }
    cout << pq.top();
    return 0;
}