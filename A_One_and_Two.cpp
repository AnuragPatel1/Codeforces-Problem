#include <bits/stdc++.h>
using namespace std;

#define int long long int


void solve() {
   int n; cin >> n;
   int ans = 0;
    bool flag = true;
    vector<int>arr(n);
    int one = 0;
    int two = 0;
   for(int i = 0; i < n; i++){
       int num; cin >> num;
       if(num == 1) one++;
       else two++;
       arr[i] = num;
   }
   
   if(two == 0){
    cout << 1 << endl;
    return;
   }


   if(two % 2 != 0){
    cout << -1 << endl;
    return;
   }
   else{ int key = two / 2;
      for(int i = 0; i  <n; i++){
          if(arr[i] == 2){
             key -- ;
             if(key == 0){
                cout << i+1 << endl;
                return;
             }
          }
      }
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