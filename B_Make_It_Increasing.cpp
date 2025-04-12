#include <bits/stdc++.h>
using namespace std;


#define mod 1000000007
#define ll long long

void solve() {
  int n; cin >> n;
  vector<int>arr(n);
  for(auto &i : arr) cin >> i;
  if(n == 1){cout << 0 << endl; return;}
  int ans = 0;
  reverse(arr.begin(),arr.end());
  for(int i = 0; i < n-1; i++){
    if(arr[i] == 0){
      cout << -1 << endl;
      return;
    }
    
  }

  for(int i = 0; i < n-1; i++){
    while(arr[i] <= arr[i+1]){
        arr[i+1] = (arr[i+1] >> 1);
        ans ++;
        if(arr[i+1] == 0 && (i+2) != n){
            cout << -1 << endl;
            return;
        }
    }
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