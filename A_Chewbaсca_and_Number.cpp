#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    string n; cin >> n;
    for(int i = 0; i < n.length(); i++){
        if((n[i]-'0') > 4){
            n[i] = (9-(n[i]-'0')) + '0';
        }
    }
    int ans = stoi(n);
    cout << ans << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t = 1;
    // std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}