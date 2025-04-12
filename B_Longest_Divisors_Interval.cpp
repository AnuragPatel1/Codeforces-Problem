#include <bits/stdc++.h>
using namespace std;

#define int long long int

void solve() {
   int n; cin >> n;
   if(n&1){
    cout << 1 << endl;
    return;
   }
   else{
      int ans = 2;
      for(int i = 3; i <= n/2; i++){
          if(n % i == 0) ans++;
          else break;
      }
      cout << ans << endl;
      return;
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