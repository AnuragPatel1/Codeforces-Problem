#include <bits/stdc++.h>
using namespace std;

#define int long long int

void solve() {
   int n,k; cin >> n >> k;
   string s; cin >> s;
   map<char,int>m;
   for(auto i : s){
      if(m.find(i) != m.end())m[i]++;
      else m[i] = 1;
   }
   
   for(auto i : m){
       if(k==0) break;
       if(i.second % 2 != 0){
          m[i.first] = 2;
          k--;
       }
       
   }
   bool flag = true;
   for(auto i : m){
       if(i.second % 2 != 0 && flag){
        flag = false;
       }
       else if(i.second % 2 != 0 && !flag){
           cout << "NO" << endl;
           return;
       }
   }
   cout << "YES" << endl;
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