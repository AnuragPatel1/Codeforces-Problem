#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define mod 1000000007

void solve() {
    int l,r; cin >> l >> r;
    if(r-l == 2 && (l&1)) cout<< 1 << endl;
    else if(r-l == 2 && !(l&1)) cout << 0 << endl;
    else if(r-l < 2) cout << 0 << endl;
    else if(l&1){
        int len = (r-l+1);
        // cout << len;
        int ans = 0;
        if(len % 4 == 3) ans++;
        ans += len/4;
        cout << ans << endl;
        return;
    }
    else{
        int ans = (r-l+1)/4;
        // if((r-l+1)%4 == 0)
        cout << ans << endl;
    }

    
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