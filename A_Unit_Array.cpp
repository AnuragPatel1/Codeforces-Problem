#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;cin >>n;
    int posi = 0;
    int neg = 0;
    for(int i = 0; i < n; i++){
        int num;cin >> num;
        if(num == -1) neg++;
        else posi++;
    }
    if(posi >= neg && (neg % 2 != 0)){
        cout << 1 << endl;
    }
    else if(neg > posi){
        int ans = neg - posi;
        if(ans % 2 != 0) ans = ans/2 + 1; 
        else ans = ans/2;
        if((neg-ans)% 2 != 0){
            cout << ans+1 << endl;
        }
        else{
            cout << ans << endl;
        }
    }
    else cout << 0 << endl;
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