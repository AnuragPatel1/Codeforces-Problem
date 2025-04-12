#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define mod 1000000007
#define ll long long
void solve() {
   int n,x,y; cin >> n >> x >> y;
//    vector<int>arr(n+2);
   int ans = 0;
   while(n--){
    int num; cin >> num;
      if(num & 1ll) ans = !ans;
   }
   if(x&1ll) ans = !ans;
   if(y&1ll) ans = !ans;

   if(ans&1ll) cout <<"Bob" << endl;
   else cout <<"Alice" << endl;
    
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