#include <bits/stdc++.h>
using namespace std;

#define int long long int



void solve() {
    string a,b; cin >> a >> b;
    int index = 0;
    for(int i = b.length()-1; i>=0;i--){
        if(b[i] == '0'){
            index++;
        }
        else break;
    }
    
    // cout << index <<" ";

    if(index == b.length()){
        cout << 0 << endl;
        return;
    }

    string x = a.substr(0,a.length()-index);
    string y = b.substr(0,b.length()-index);

    // cout << x  << " " << y << " ";
    
    int ans = 0;
    for(int i = x.length()-1; i >= 0; i--){
        if(x[i] == '1'){
            cout << ans << endl;
            return;
        }
        else ans++;
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