#include <bits/stdc++.h>
using namespace std;

#define int long long int


void solve() {
   int n; cin >> n;
   int ans = 0;
   while(n > 0){
      if(n & 1) ans++;
      n = n >> 1; 
   }
   cout << ans << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    // std::cin >> t;
    t = 1;
    while (t--) {
        solve();
    }
    
    return 0;
}