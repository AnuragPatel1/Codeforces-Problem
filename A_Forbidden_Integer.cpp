#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n,k,x; cin >> n >> k >> x;
    if(x != 1){
        cout << "YES" << endl;
        cout << n << endl;
        for(int i = 0; i < n; i++) cout << 1 <<" ";
        cout << endl;
    }
    else if(k == 1 && x == 1) cout <<"NO" << endl;
    else if(x == 1 && k == 2 && n % 2 != 0 ) cout << "NO" << endl;
    else{
        cout << "YES" << endl;
        cout << n/2 << endl;
        if(n  % 2 != 0){
            cout << 3 <<" ";
            n = n-3;
            for(int i = 0; i < n/2; i++){
                cout << 2 << " ";
            }
            cout << endl;
        }
        else{
            for(int i = 0; i < n/2; i++){
                cout << 2 << " ";
            }
            cout << endl;
        }
    }
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