#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
   int n; cin >> n;
   map<int,int>m;
   int i = 1;
   while(i <= n){
    int num;cin >> num;
    m[num] = i;i++;
   }
   for(auto i :m) cout << i.second<<" ";
   cout << endl;
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