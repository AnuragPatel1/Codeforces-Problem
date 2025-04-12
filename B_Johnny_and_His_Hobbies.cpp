#include <bits/stdc++.h>
using namespace std;

#define int long long int



void solve() {
   int n; cin >> n;
   map<int,bool>m;
   vector<int>arr(n);
   for(int i = 0; i < n;i++){
      int num ; cin >> num;
      arr[i] = num;
       m[num] = false;
   }
   int ans = 1;
   while(ans < 1024){
    int i = 0;
      while(i < n){
            int temp = ans^arr[i];
            // cout << temp <<" ";
            if(m.find(temp) != m.end()){
                if(m[temp] == false) m[temp] = true;
                else{
                    for(auto &it:m) it.second = false;
                    break;
                }
                i++;
                if(i == n){cout << ans << endl; return;}
            }
            else {
                for(auto &it:m) it.second = false;
                break;
            }
      }
       ans++;
   }
   cout << -1 << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    // cout <<__builtin_popcount(1.09951162778E+12) << endl;

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}