#include <bits/stdc++.h>
using namespace std;

#define int long long int

void solve() {
   int n, k; cin >> n >> k;
   vector<int> arr(n);
   int ans = 0;
   int a = 0;
   int b = 0;
   for(int i = 0; i < n; i++){
       cin >> arr[i];
   }
    sort(arr.begin(), arr.end(), std::greater<int>());



    int i=0;
    while(i < n-1){
       ans += (arr[i]- arr[i+1]);
       if(k > 0){
          ans = ans - min(k,abs(arr[i]-arr[i+1]));
          k = k - min(abs(arr[i]-arr[i+1]),k);
       }
       i=i+2;
    }
    if(n % 2){
        cout<< ans + arr[n-1]<<endl;
        return;
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