#include <bits/stdc++.h>
using namespace std;

#define int long long int


void solve() {
   int n; cin >> n;
   int ans = 0;
    bool flag = true;
    vector<int>arr(n);
   for(int i = n-1; i >= 0; i--){
       int num; cin >> num;
       arr[i] = num;
   }
   
   if( arr[0] == arr[n-1]){
    cout << "NO" << endl;
   }

   else{
    if(arr[0] == arr[1]){
        swap(arr[1],arr[n-1]);
   }
   
   cout <<"YES" << endl;
   for(auto i : arr){
    cout << i <<" ";
   }
  cout << endl;
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