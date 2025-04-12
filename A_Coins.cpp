#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n,k;cin >>n >> k;
   if((n % k == 0) || (n % 2 == 0) || (n % (k+2) == 0) || (n-k) % 2 == 0) cout << "YES" << endl;
   else cout <<"NO" << endl;
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