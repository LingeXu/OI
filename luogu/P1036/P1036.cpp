#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#define N 25
#define K 25
using namespace std;
int n, k, cnt = 0, sum = 0;
vector<int> integer;
vector<bool> isprime;
vector<int> primes;
priority_queue<int, vector<int>, less<int> > pq;
void euler_sieve(int n){
    isprime[0] = isprime[1] = false;
    for(int i = 2; i <= n; i++){
        if(isprime[i])  primes.push_back(i);
        for(int p : primes){
            if(i * p > n)   break;
            isprime[i * p] = false;
            if(i % p == 0)  break;
        }
    }
}
void EnumerateByDfs(int start, int remain, int sum){
    if(remain == 0){
        cnt += isprime[sum];
        return;
    }
    if(remain > n - start)
        return;
    for(int i = start; i < n; i++)
        EnumerateByDfs(i + 1, remain - 1, sum + integer[i]);
}
int main(){
    cin >> n >> k;
    int size = n;
    while(size--){
        int x;
        cin >> x;
        integer.push_back(x);
        pq.push(x);
    }
    for(int i = 1; i <= k; i++){
        sum += pq.top();
        pq.pop();
    }
    isprime.resize(sum + 1);
    fill(isprime.begin(), isprime.end(), true);
    euler_sieve(sum);
    EnumerateByDfs(0, k, 0);
    cout << cnt;
    return 0;
}