#include <bits/stdc++.h>
using namespace std;

#define int long long int

void solve() {
   int n; cin >> n;
   string  arr; cin >> arr;
//    string arr = to_string(num);
   int temp = n - arr.size();
   bool flag = true;
   while(temp > 0){
      arr = "0" + arr;
      temp--;
   }
   if(n == 1){
    cout << 1 << endl;
    flag = false;
    return;  //  cout << i <<"=" <<j <<" ";
   }
   int i = 0;
   int j = n-1;
   while(i <= j){
       if((arr[i] == '0' && arr[j] == '1') || (arr[i] == '1' && arr[j] == '0')){
            i++;
            j--;
       }
       else{ 
          cout << (j-i)+1 << endl;
          flag = false;
          return;
       }
   }

   if(flag) cout << 0 << endl;
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