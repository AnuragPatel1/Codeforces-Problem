#include <bits/stdc++.h>
using namespace std;

#define int long long int



void solve() {
   int n; cin >>n;
   int ans = 0;
   bool flag = true;
   for(int i = 0; i< n; i++){
    int num; cin >> num;
      if(flag) {ans+= num; flag = false;}
      else {ans-=num; flag = true;}
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