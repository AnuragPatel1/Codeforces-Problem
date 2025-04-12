#include <bits/stdc++.h>
using namespace std;

#define int long long


void solve() {
     int n,k; cin >> n >>k;
     vector<int>arr(n);
     
     int maxi = 0;

     for(int i = 0; i < n; i++){
        int num; cin >> num;
        arr[i] = num;
        if(maxi < num) maxi = num;
     }
     
     while(maxi){
        int count = 0;
        for(int i = 0; i < n; i++){
            
            int chk = arr[i]%k;
            // cout << chk;
            arr[i] /= k;
            if(chk != 0 && chk != 1){cout <<"NO" << endl; return;}
            if(chk == 1) count++;
        }
        if(count > 1){cout <<"NO" << endl; return;}
        maxi = maxi/k;
     }
   cout <<"YES" << endl;
   
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