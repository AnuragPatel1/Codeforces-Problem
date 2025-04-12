#include <bits/stdc++.h>
using namespace std;

#define int long long int

void solve(){
    int n; cin >> n;
    vector<int>arr(n);
    // int ans = 0;
    for(int i = 0; i < n; i++) cin >> arr[i];

      int ans = (arr[n-1]-arr[0]);
    for(int i = 1; i < n; i++){
        ans = max(ans,(arr[n-i]-arr[0]));
    }
    for(int i = 0;i < n-1; i++){
        ans = max(ans,(arr[n-1]-arr[i]));
    }
    for(int i = 0; i < n-1; i++){
        ans = max(ans,(arr[i]-arr[i+1]));
    }
    cout << ans << endl;
}


signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}