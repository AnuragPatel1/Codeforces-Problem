#include <bits/stdc++.h>
using namespace std;

#define int long long int

void solve() {
   int n,k ; cin >> n >> k;
   vector<int>arr(n*k);
   for(int i = 0; i < n*k;i++){
      cin >> arr[i];
   }
  
       int ans = 0;
       int i = (n*k-1)-n/2;
       while(i >= 0){
           ans += arr[i];
           k--;
           if(k == 0) break;
           i = i - n/2 - 1;
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