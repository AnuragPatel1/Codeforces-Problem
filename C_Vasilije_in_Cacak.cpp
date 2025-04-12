#include <bits/stdc++.h>
using namespace std;

#define int long long int

void solve() {
   int n,k,x; cin >> n >> k >> x;
   int least = (k*(k+1))/2;
   int most = (k*((2*(n+1-k) + k-1)))/2;

   if(x <= most && x >= least) cout <<"YES" << endl;
   else cout << "NO" << endl;
   
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