#include <bits/stdc++.h>
using namespace std;

#define int long long int

void solve() {
  int n; cin >> n;
  int ans = 0;
  vector<int>arr(n);
  for(int i = 0; i <n;i++){
     cin >> arr[i];
    if(!i) ans = arr[i];
    else ans = arr[i]&ans;
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