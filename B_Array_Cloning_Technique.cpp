#include <bits/stdc++.h>
using namespace std;

#define int long long int



void solve() {
     int n; cin >> n;
    //  if(n == 1) {cout << 0 << endl; return;}
     
     int ans = 0;
     map<int,int>m;
     for(int i = 0; i < n; i++){
        int num; cin >> num;
        // cout << num <<" ";
        if(m.find(num) != m.end()) m[num]++;
        else m[num] = 1;
     }
     
    //  cout << m.size() <<" ";
     if(m.size() == 1){cout << 0 << endl; return;}
    //  cout << "Hi" <<" ";
     int target=-1;
     int temp = -1;
     for(auto i : m){
         if(i.second > temp){
              target = i.first;
              temp = i.second;
         }
     }
     
    //  cout << target <<" ";

     int consist = m[target];
     int rem = n - consist;
     
     while(rem > 0){
        temp = min(rem,consist);
        ans += (1 + temp);
        rem -= min(rem,consist);
        consist = consist << 1;
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