#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
   int n, total; cin >> n >> total;
   vector<pair<int,int>>arr(n);
   int k = 1;
   for(int i = 0; i < n; i++){
    int num; cin >> num;
    arr[i] = (make_pair(num,k));
    k++;
   }
   sort(arr.begin(),arr.end());
   
   int count =0;
   vector<int>ans;
   for(auto &i : arr){
       if(i.first <= total){
         ans.push_back(i.second);
        //  cout << i.second <<" ";
         total -= i.first;
       }
       else break;
   }
   cout << ans.size() << endl;
   for(auto &i :ans) cout << i  << " ";
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