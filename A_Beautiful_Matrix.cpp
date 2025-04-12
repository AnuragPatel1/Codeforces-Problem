#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
   int i = 1;
   pair<int,int>coor;
   while( i <= 5){
     int j = 1;
      while(j <= 5){
          int num; cin >> num;
          if(num == 1){coor = (make_pair(i,j));}
          j++;
      }
      i++;
   }
   int ans = abs(3-coor.first) + abs(3-coor.second);
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