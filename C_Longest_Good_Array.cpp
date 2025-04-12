#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int l,r; cin>>l >> r;
  int k = 1;
  int count = 0;
  while(l <= r){
    count++;
    l = l+k;
    k++;
  }
  cout << count << endl;
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