#include <bits/stdc++.h>
using namespace std;

#define int long long


void solve() {
   int n,k; cin >> n >> k;
   if(n < k){
    cout <<"NO" << endl; return;
   }
   int set = __builtin_popcount(n);
   if( set > k){cout <<"NO" << endl; return;}
   if(set == k){
      cout << "YES" << endl;
      int ans = 0;
      int p = 0;
      while(n){
         if(n&1){
            ans += (1 << p);
            cout << ans <<" ";
            ans = 0;
         } 
         p++;
         n = n/2;
      }
   return;
   }
   else{
      cout << "YES" << endl;
      if(n&1){n--;k--; cout << 1 <<" ";}
      int size = 0;
      vector<int>arr(32,0);
      int p = 0;
    //   cout << n <<" ";
      while(n){
         if(n&1){
            arr[p] = 1;
            size++;
         } 
         p++;
         n = n/2;
      }
     
     int rem = k - size;
     
    //  for(auto i:arr) cout << i <<" ";
    
        
    while(rem){
        // cout<< rem <<" " ;
            for(int i = 31; i > 0; i--){
            if(rem == 0) break;
            if(arr[i] == 0) continue;
            arr[i]--;
            arr[i-1]+=2;
            rem--;
        }
    }

     for(int i = 0; i < 32; i++){
        if(arr[i] != 0){
           while(arr[i]){
               cout << (1 << i) <<" ";
               arr[i]--;
           }
        }
     }
     
cout << endl;

   }

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