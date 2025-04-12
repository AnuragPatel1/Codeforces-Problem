#include <bits/stdc++.h>
using namespace std;

#define int long long int

void solve() {
   int n,x; cin >> n >> x;
   int maxi = 0;
   int mini = 0;
   int sum = 0;
   for(int i = 0; i < n; i++){
      int num; cin >> num;
      sum += num;
      int temp = num % x;
      if(temp == 0){
        maxi += num / x;
      }
      else{
        maxi += (num/x);
        maxi += 1;
      }
   }
   if(sum % x == 0) mini = sum / x;
   else mini = (sum / x) +1 ;

   cout<< mini <<" " << maxi << endl;
  
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