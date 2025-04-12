#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define ll long long

void solve() {
  int n; cin >> n;
  int even = 0;
  int odd = 0;

  vector<int>arr(n);
  for(int i = 0; i <n;i++){
    int num; cin>>num;
    arr[i] = num;
    if(num & 1) odd++;
    else even++;
  }

  if(even != 0 && odd != 0) {cout << 2 << endl; return;}
  for(int j = 0; j < 64;j++){
      set<int>s;
      for(int i = 0; i <n; i++){
          s.insert(arr[i] & ( 1ll << j));
      }
      if(s.size() == 2){
        cout << (1ll << j+1) << endl;
        return;
      }
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