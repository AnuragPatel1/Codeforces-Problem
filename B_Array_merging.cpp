#include <bits/stdc++.h>
using namespace std;

#define int long long int

void solve() {
   int n; cin >> n;
   if(n == 1){
      int a,b; cin >> a >> b;
      if(a != b) cout << 1 << endl;
      else cout << 2 << endl;
      return ;
   }

   map<int,int>m1;
   map<int,int>m2;
   int prev ; cin >> prev;
   int count = 1;
   for(int i = 0; i < (n-1); i++){
       int num; cin >> num;
       if(num == prev){
            count += 1;
       }
       else{
          m1[prev] = max(count,m1[prev]);
          prev = num;
          count = 1;
       }

       if(i == n-2){
          if(num == prev) m1[prev] = max(count,m1[prev]);
          else m1[num] = max(m1[num],count);
       }
   }

    cin >> prev;
    count = 1;
   for(int i = 0; i < (n-1); i++){
       int num; cin >> num;
       if(num == prev){
            count += 1;
       }
       else{
          m2[prev] = max(count,m2[prev]);
          prev = num;
          count = 1;
       }

       if(i == n-2){
          if(num == prev) m2[prev] = max(count,m2[prev]);
          else m2[num] = max(m2[num],count);
       }
   }

   int ans = 1;
  for(auto i : m1){
    ans = max(ans,i.second);
    if(m2.find(i.first) != m2.end()) {
        ans = max(ans, i.second + m2[i.first]);
    }
}
for(auto i : m2){
    ans = max(ans,i.second);
    if(m1.find(i.first) != m1.end()) {
        ans = max(ans, i.second + m1[i.first]);
    }
}


   cout << ans << endl;

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