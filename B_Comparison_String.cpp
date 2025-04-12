#include <bits/stdc++.h>
using namespace std;

#define int long long int

void solve() {
  int n;cin >>n;
  string s; cin >> s;
  int ans = 0;
  bool flag = true;
  char temp ;
  int count = 1;
  for(auto i : s){
      if(flag){
         temp = i;
         flag = false;
      }
      else if(temp == '<' && i == '<') count++;
      else if(temp == '>' && i == '>') count++;
      else{
        ans = max(count,ans);
        count = 1;
      }
      temp = i;
  }
  ans = max(count,ans);
  cout << ans+1 << endl;
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