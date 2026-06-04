#include <bits/stdc++.h>
#define N 1000010
typedef long long ll;
using namespace std;
int n;
int h[N], v[N], s[N], energy[N];
ll get_energy[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) 
        cin >> h[i] >> v[i];
    int top = 0;
    for(int i = 1; i <= n; i++) {
        while(top > 0 && s[top] < h[i]) {
            get_energy[i] += 1LL * energy[top];
            top--;
        }
        s[++top] = h[i];
        energy[top] = v[i];
    }
    top = 0;
    memset(s, 0, sizeof(s));
    memset(energy, 0, sizeof(energy));
    for(int i = n; i >= 1; i--) {
        while(top > 0 && s[top] < h[i]) {
            get_energy[i] += 1LL * energy[top];
            top--;
        }
        s[++top] = h[i];
        energy[top] = v[i];
    }
    sort(get_energy + 1, get_energy + n  + 1, greater<ll>());
    cout << get_energy[1];
    return 0;
}