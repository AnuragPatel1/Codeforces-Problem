#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define INF 1e18

void solve() {
    int n; cin >> n;
    vi a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }

    vector<vi> dp(n, vi(3, INF));

    for (int j = 0; j < 3; ++j) {
        dp[0][j] = j * b[0];
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 3; ++j) { 
            for (int k = 0; k < 3; ++k) { 
                if (a[i] + j != a[i-1] + k) {
                    dp[i][j] = min(dp[i][j], dp[i-1][k] + j * b[i]);
                }
            }
        }
    }

    int ans = min({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q; cin >> q;
    while (q--) solve();
}
