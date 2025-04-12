#include <bits/stdc++.h>
using namespace std;

#define int long long int

void solve() {
  int n,k; cin >> n >> k;
  vector<int>arr(n);
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
   
   sort(arr.begin(),arr.end());
   int ans = 0;
   int temp = 0;
   bool flag = true;
   for(int i = 0; i < n-1;i++){ 
      if((arr[i+1]-arr[i]) <= k) temp++;
      else{
        ans = max(ans,temp);
        temp = 0;
        flag = false;
      }
   }
   ans = max(ans,temp);
 if(flag) cout << 0 << endl;
 else cout << n-ans-1 << endl;
   
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