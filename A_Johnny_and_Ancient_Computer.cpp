#include <bits/stdc++.h>
using namespace std;

#define int long long int



void solve() {
   int a,b; cin >> a >> b;
   if(a < b){
      a = a^b; b = a^b; a = a^b;
   } 
   int req = a / b;
   if((req == 1) && (a % b == 0)){cout << 0 << endl; return;}
   else if(a % b != 0) cout << -1 << endl;
   else if(__builtin_popcountll(req) != 1) cout << -1 << endl;
   else {
    // cout << req <<" ";
    int count = 0;
      while(req >= 8){
         req = req/8;
         count++;
      }
      if(req == 1) cout << count << endl;
      else if(req == 2 || req == 4) cout << count+1 << endl;
      else cout << -1 << endl;
   }

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    // cout <<__builtin_popcount(1.09951162778E+12) << endl;

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}