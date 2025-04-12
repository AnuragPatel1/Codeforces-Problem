#include <bits/stdc++.h>
using namespace std;

#define int long long int



void solve() {
   int a,b; cin >> a >> b;
   if(a != 1 && b != 1){cout << 1 << endl; return;}
   else if(a != 2 && b != 2){cout << 2 << endl; return;}
   else cout << 3 << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    // std::cin >> t;
    t = 1;
    while (t--) {
        solve();
    }
    
    return 0;
}