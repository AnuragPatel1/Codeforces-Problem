#include <bits/stdc++.h>
using namespace std;

#define int long long int

void solve() {
   int n; cin >> n;
   int two = 0;
   int three = 0;
   while(n > 1){
      if((n % 3 != 0) && (n % 2 != 0)){
           cout << -1 << endl;
           return;
      }
      if(n % 3 == 0){
          three ++;
          n = n/3;
      }
      if(n % 2 == 0){
          two ++;
          n = n/2;
      }
   }
   if(three < two){
    cout << -1 << endl;
    return;
   }
   else if(two == three){
    cout << three << endl;
   }
   else{
       int ans = (three - two);
       ans += three;
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