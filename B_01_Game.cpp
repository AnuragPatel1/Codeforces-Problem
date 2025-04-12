#include <bits/stdc++.h>
using namespace std;

#define int long long int

void solve() {
   string s; cin >> s;
   int one = 0;
   int zero = 0;
   for(auto i : s){
        if(i == '0') one++;
        else zero++;
   }
   if(min(one,zero) % 2 == 0)
      cout <<"NET" << endl;
   else cout <<"DA" << endl;

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