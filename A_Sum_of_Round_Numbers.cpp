#include <bits/stdc++.h>
using namespace std;

#define int long long



void solve() {
   string n; cin >>n;
   int j = 1;
   vector<int>ans;
   for(int i = n.length()-1; i >= 0;i--){
      if(n[i] != '0'){
        ans.push_back((n[i]-'0')*j);
      }
        j *= 10;
   }
   cout << ans.size() << endl;
   for(auto i :ans) cout << i <<" ";
   cout << endl;
 }

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t ;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}