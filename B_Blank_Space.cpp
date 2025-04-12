#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;cin >>n;
    int count = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        if(num != 0 ){
          ans = max(ans,count);
          count = 0;
        }
        else count++;
    }
    ans = max(count,ans);
    cout<< ans << endl;
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