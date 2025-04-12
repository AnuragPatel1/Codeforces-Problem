#include <bits/stdc++.h>
using namespace std;

#define int long long int

void solve() {
  int n; cin >> n;
  int zero = 0;
  int one = 0;
  for(int i = 0; i < n; i++){
      int num; cin >> num;
      if(num == 0) zero++;
      if(num == 1) one++;
  }
  if(one == 0){
    cout << 0 << endl;
    return;
  }
  
  if((one == 1 && zero == 0)|| (one == 2 && zero == 0)) cout << one << endl;
else if(one == 1 && zero == n-1) cout << 2*n << endl;
  else if(one > 0 && zero == 0){cout << ((one-1)*2)-1 << endl; return;}
  else cout<<(one+zero-1)*2 << endl;

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