#include <bits/stdc++.h>
using namespace std;

#define int long long int



void solve() {
     int a,b,c; cin >> a >> b >> c;
     b = b * 2;
     if(b == (a+c)){
        cout << "YES" <<endl;
     }
     else if(b < (a+c)){
        if((a+c)%b == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
      }
      else{
        if((b-c)%a == 0  || (b-a)%c == 0) cout <<"YES" << endl;
        else cout <<"NO" << endl;
      }
      return;
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