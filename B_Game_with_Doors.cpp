#include <bits/stdc++.h>
using namespace std;

#define int long long int

void solve() {
  int a,b,c,d; cin >> a>>b>>c>>d;
  if(c>b|| a  > d ){
    cout << 1 << endl;
    return;
  }
//   else if(b == c) cout << 2 << endl;
  else if(a == c && b == d){
    cout << b-a << endl;
    return;
  }
  int e = min(b,d);
  int f = max(a,c);

  int ans = (e - f) + 2;
  if(a == c) ans -= 1;
  if(b==d) ans-=1;

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