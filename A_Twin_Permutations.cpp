#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;cin >>n;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        cout << (n+1)-num <<" ";
    }
    cout << endl;
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