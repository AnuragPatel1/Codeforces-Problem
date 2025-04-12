#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>

void solve() {
    ll n, k;
    cin >> n >> k;
    vl arr(n);
    for (ll &x : arr) cin >> x;
    
    sort(arr.begin(), arr.end()); 
    
    ll ans = 0, team_size = 0;
    
    for (ll i = n - 1; i >= 0; i--) { 
        team_size++;
        if (team_size * arr[i] >= k) {
            ans++;       
            team_size = 0; 
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
