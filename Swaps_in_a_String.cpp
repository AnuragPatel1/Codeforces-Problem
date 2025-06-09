#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> best(n, 0);
    ll ct = 0;

    for (ll i = 0; i < n; ++i) {
        if (s[i] == 'A') ct++;
        else if (s[i] == 'B') best[i] = ct;
        else ct = 0;
    }

    ct = 0;
    for (ll i = n - 1; i >= 0; --i) {
        if (s[i] == 'A') ct = 0;
        else if (s[i] == 'B') best[i] = max(best[i], ct);
        else ct++;
    }

    ll ans = accumulate(best.begin(), best.end(), 0LL);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
