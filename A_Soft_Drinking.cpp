#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
   int n,k,l,c,d,p,nl,np; cin >> n>>k>>l>>c>>d>>p>>nl>>np;
   int ans = min((k*l)/nl , min(c*d , (p/np)));
   cout << ans/n << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t = 1;
    // std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}