#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
   string s;cin >> s;
   int w = 0;
   for (int i = 0; i < s.size(); i++) if (s[i] == '4' || s[i] == '7') w++;
	if (w == 4 || w == 7) cout << "YES\n"; else cout << "NO\n";
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