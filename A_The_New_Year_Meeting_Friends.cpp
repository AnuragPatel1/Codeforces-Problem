#include <bits/stdc++.h>
using namespace std;

#define int long long

int solve(int a,int b,int c,int point){
  return abs(a-point) + abs(b-point) + abs(c-point);
}

void solve() {
   vector<int>arr(3);
   for(int i = 0; i < 3; i++) cin>> arr[i];
   sort(arr.begin(),arr.end());
   int ans = INT_MAX;
   for(int i = arr[0];i <= arr[2];i++){
      ans= min(ans,solve(arr[0],arr[1],arr[2],i));
   }
   cout << ans << endl;
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