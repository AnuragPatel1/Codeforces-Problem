#include <bits/stdc++.h>
using namespace std;

#define int long long int

void solve() {
   int n; cin >> n;
   vector<int>arr(n);
   for(int i = 0; i < n; i++){
    int num; cin >> num;
    arr[i] = num;
   }
//    
   if(n > 2){
     cout <<"NO" << endl;
   }
   else{
    sort(arr.begin(),arr.end());
    if((arr[1] - arr[0]) > 1){
        cout <<"YES" << endl;
    }
    else cout <<"NO" << endl;
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