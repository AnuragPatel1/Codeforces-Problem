#include <bits/stdc++.h>
using namespace std;

#define int long long int


void solve() {
  int n; cin >> n;
  vector<int>arr(n);
  for(int i = 0; i < n; i++){
    int num ; cin >> num;
    if(num == 1) num++;
     arr[i] = num;
  }
// for(auto i:arr) cout<<i<<" ";
  int i = 0;
  while(i < n-1){
      if(arr[i+1] % arr[i] == 0){
         arr[i+1]+=1;
      }
      i++;
  }
  for(auto i:arr) cout<<i<<" ";
  cout << endl;

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