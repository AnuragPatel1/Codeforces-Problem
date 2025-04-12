#include <bits/stdc++.h>
using namespace std;

#define int long long int


void solve() {
   int n; cin >> n;
   int ans = 0;
//    bool flag = true;
    vector<int>arr(n);
   for(int i = 0; i < n; i++){
       int num; cin >> num;
       arr[i] = num;
   }

   for(int i = 0; i < n-1; i++){
        if((arr[i] % 2 == 0) && (arr[i+1] % 2 == 0)) ans++;
        else if((arr[i] % 2 != 0) && (arr[i+1] % 2 != 0)) ans++;
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