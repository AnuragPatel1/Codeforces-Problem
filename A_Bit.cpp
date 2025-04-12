#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n,k; cin >> n >> k;
    // cout << n << " "<<k <<" ";
    vector<vector<int>>arr;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        // bitset<32>b(a);
        // vector<int>temp(32);
        // for(int j = 0; j < 32;j++){
        //     temp[j] = b[j];
        // }
        // arr.push_back(temp);
    }
    
    // for(auto i :arr){
    //     for(auto j : i) cout <<j <<" ";
    //     cout << endl;
    // }
   cout << k <<" " << n;
    
    if(k >= n){
        cout << k <<" ";
       for(int i = 30; i >= 0; i--){
          for(int j = 0; j < n; j++){
            if(arr[i][j] != 1) arr[i][j] = 1,k--;
          }
          if(k < n) break;
       } 
    }
    
    int ans = 0;

    for(int i = 31; i >= 0;i++){
        int count = 0;
        for(int j = 0; j < n; j++){
           if(arr[i][j] == 1) count++;
        }
        if(count == n) ans+= (1 << i);
        else if(count+k >= n) ans+=(1 << i);
    }
    out(ans);

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