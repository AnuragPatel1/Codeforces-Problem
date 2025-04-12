#include <bits/stdc++.h>
using namespace std;

#define int long long int


void solve() {
   int n; cin >> n;
   int ans = 0;
   if(n <= 10){
    cout << n << endl;
    return;
   }
   else if(n <= 100){
      int c = n / 10;
      cout << (10+c-1) << endl;
   }
   else{
       string s = to_string(n);
       while(s.length() > 3){
           ans += 10;
           s.pop_back();
       }
       ans = ans +(s[0] -'0')+ 18;
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