#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
   int n; cin >> n;
   vector<int>arr(n);
   bool flag = true;
   for(int i = 0; i < n; i++){
    int num; cin >> num;
    if(num&1){
        if(flag) num += 1;
        else num-=1;
        flag = !flag;
    }
    arr[i] = num;
   }
   for(auto i : arr){
    cout << i/2 << endl;
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