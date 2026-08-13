#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAXN = 10005; // 2 * max n = 2 * 5000

int dp[5005]; // dp[j]: number of ways with j additional UP steps placed
int forced[MAXN]; // forced[i]: number of forced UP positions in [1, i]

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    // Check if any forced element is too large
    // In any valid S, s_n <= 2n-1, so all elements are <= 2n-1
    if (m > 0 && a.back() > 2 * n - 1) {
        cout << "0\n";
        return;
    }

    // Check necessary condition: for the j-th smallest forced element a_j,
    // its earliest possible position is j, so we need a_j <= 2*(n-m+j) - 1
    // (worst case: all additional elements come before it)
    for (int j = 0; j < m; j++) {
        int earliest_pos = j + 1; // at least j elements before it
        if (a[j] > 2 * (n - m + j + 1) - 1) {
            cout << "0\n";
            return;
        }
    }

    // Build forced prefix counts for positions 1..2n
    int totalPos = 2 * n;
    fill(forced, forced + totalPos + 1, 0);
    for (int x : a) {
        if (x <= totalPos) {
            forced[x]++;
        }
    }
    for (int i = 1; i <= totalPos; i++) {
        forced[i] += forced[i - 1];
    }

    int additional = n - m; // number of additional UP steps to place

    fill(dp, dp + additional + 1, 0);
    dp[0] = 1; // 0 positions processed, 0 additional UP placed

    for (int i = 1; i <= totalPos; i++) {
        int f = forced[i]; // forced UP in [1, i]
        int need = (i + 1) / 2; // minimum total UP needed: ceil(i/2)

        // Iterate j from high to low for in-place update
        for (int j = additional; j >= 0; j--) {
            int total_up = f + j;
            if (total_up < need) {
                dp[j] = 0; // constraint violated
                continue;
            }

            // Check if this position is forced UP
            bool is_forced = (forced[i] > forced[i - 1]);

            if (is_forced) {
                // Must be UP, no additional UP consumed
                // dp[j] stays the same (value from dp[j] of previous i)
                // Already in dp[j] from previous iteration
            } else {
                // Not forced: can be DOWN or additional UP
                // DOWN: dp[j] += dp[j] (from previous) — already there
                // UP: dp[j] += dp[j-1] (from previous)
                if (j > 0) {
                    dp[j] = (dp[j] + dp[j - 1]) % MOD;
                }
                // if j == 0, only DOWN is possible: dp[0] stays
            }
        }
    }

    cout << dp[additional] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
