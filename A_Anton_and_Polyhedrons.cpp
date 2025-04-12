#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
   int n; cin >> n;
   map<string,int>m;
   m["Tetrahedron"] = 4;
   m["Cube"] = 6;
   m["Octahedron"] = 8;
   m["Dodecahedron"] = 12;
   m["Icosahedron"] = 20;
   int ans = 0;
   while(n--){
    string s; cin >> s;
    ans += m[s];
   }
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