#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define mod 1000000007

void solve() {
   int n,k; cin>>n>>k;
   int maxi = INT_MIN;
   for(int i = 0; i < n; i++){
      int num; cin >> num;
      if(num > maxi) maxi = num;
   }

   while(k--){
      char sign ; cin>>sign;
      if(sign == '+'){
        int l,r ; cin>>l >>r;
        if(maxi >= l && maxi <= r) maxi++;
        cout << maxi <<" ";
      }
      else{
        int l,r ; cin>>l >>r;
        if(maxi >= l && maxi <= r) maxi--;
        cout << maxi <<" ";
      }
   }
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