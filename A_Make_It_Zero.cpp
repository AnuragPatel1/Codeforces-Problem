#include <bits/stdc++.h>
using namespace std;

#define int long long int

void solve() {
 int n ; cin >> n;
 vector<int>arr(n);
 int index = -1;
 int ans = -1;
 for(int i= 0 ;i < n; i++){ cin >> arr[i];
 if(arr[i] == 0) index = i+1;
 if(i > 0 && arr[i-1] == arr[i]) ans = i+1;
 }
 if(!(n & 1)){
    cout << 2 << endl;
 cout << 1 << " " << n << endl; 
 cout << 1 << " " << n << endl; 
 }
 else{
    cout << 4 << endl;
    cout << 1 << " " << n-1 << endl;
    cout << 1 << " " << n-1 << endl;
    cout << n-1 << " " << n << endl;
    cout << n-1 <<" " << n << endl;
    
 }

//  else if(index != -1){
//     cout << 4 << endl;
//     cout << 1 << " " << index-1 << endl;
//     cout << index+1 <<" " << n << endl;
//      cout << 1 << " " << index-1 << endl;
//     cout << index+1 <<" " << n << endl;

//  }
//  else{
//      if(ans == 2){
//         cout << 3 << endl;
//         cout << 1 << " " << 2 << endl;
//         cout << 2 << " " << n << endl;
//         cout << 2 << " " << n << endl;
//      }
//      else if(ans == n){
//          cout << 3 << endl;
//         cout << n-1 << " " << n << endl;
//         cout << 1 << " " << n-1 << endl;
//         cout << 1 << " " << n-1 << endl;
//      }
//      else{
//         cout << 5 << endl;
//         cout << ans-1 << " " << ans << endl;
//         cout << 1 << " " << ans << endl;
//         cout << 1 << " " << ans << endl;
//         cout << ans << " " << ans-1 << endl;
//         cout << 1 << " " << ans-1 << endl;
//      }
//  }
 
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