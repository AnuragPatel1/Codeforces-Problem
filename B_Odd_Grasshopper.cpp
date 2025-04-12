#include <bits/stdc++.h>
using namespace std;

#define int long long int

void solve() {
   int x, n;
    cin >> x >> n;
    if(!(x & 1)){
        if(n % 4 == 0) cout << x << endl;
        else if(n % 4 == 3) cout << x+n+1 << endl;
        else if(n % 4 == 2) cout << x+1 << endl;
        else cout << (x-n) << endl;
        return;
    }
    else{
        if(n % 4 == 0) cout << x << endl;
        else if(n % 4 == 3) cout << x-n-1 << endl;
        else if(n % 4 == 2) cout << x-1 << endl;
        else cout << (x+n) << endl;
        return;
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