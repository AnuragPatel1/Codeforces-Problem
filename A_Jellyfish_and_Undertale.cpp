#include <bits/stdc++.h>
using namespace std;

#define int long long int

void solve() {
   int a,b,n; cin >> a >> b >> n;
   int ans = b;
   for(int i = 0; i < n; i++){
       int num;cin >> num;
       if(num >= a) ans += (a-1);
       else ans += num;
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