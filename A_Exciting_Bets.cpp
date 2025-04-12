#include <bits/stdc++.h>
using namespace std;

#define int long long int


void solve() {
   int a ,b ; cin >> a >> b;
   int ans1 = abs(a-b);
   int ans2 = min(a,b);
   if(ans1 == 0){
     cout << 0 <<" "<< 0 << endl;
     return;
   }
   
   if(a == 0 || b == 0){
    cout << ans1 <<" " <<0 << endl;
    return;
   }
   
   int x = a % ans1;
   int y = b % ans1;
   if(x == y){
      ans2 = min(ans2,min(x,ans1-x));
   }
   
   cout << ans1 <<" " << ans2 << endl;
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