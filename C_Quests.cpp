#include <bits/stdc++.h>
using namespace std;

#define int long long int

void solve() {
   int n,k; cin >> n >> k;
   vector<int>arr1(n);
   vector<int>arr2(n);
   for(int i = 0; i < n; i++) cin >> arr1[i];
   for(int i = 0; i < n; i++) cin >> arr2[i];

   int maxi = 0;
   int ans = 0;
   int sum = 0;
   for(int i = 0; i < min(n,k);i++){
        sum += arr1[i];
        maxi = max(maxi,arr2[i]);
       int temp = sum+(k-i-1)*maxi;
       ans = max(ans,temp);
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