#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
   int n; cin >> n;
   vector<int>arr(n);
   bool ans = true;
   for(int i = 0; i < n; i++){
    cin >>arr[i];
    if(arr[i]) ans = false;
   }
   if(ans) cout<<"EASY" << endl;
   else cout <<"HARD" << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t = 1;
    // std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}