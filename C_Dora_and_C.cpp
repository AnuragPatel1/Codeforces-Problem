#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define mod 1000000007
#define ll long long

int gcd(int a,int b){
    if(a < b){
        a = a^b; b = a^b; a = a^b;
    }

    while (a % b != 0) { 
    int temp = b;
       b = a % b;
       a = temp;
    } 
    return b; 
}

void solve() {
  int n,a,b; cin >> n >> a >> b;
  
  if(a != b) a = gcd(a,b); 
  
   set<int>s;
  for(int i = 0; i < n; i++){
      int num; cin >> num;
      s.insert(num%a);
  }
  int len = s.size();
   vector<int>arr(len);
  int m = 0;
  for(auto i : s){
      arr[m] = i;
      m++;
  }
  sort(arr.begin(),arr.end());
  n = len;
  int ans = arr[n-1] - arr[0];
  for(int i = 0; i < n-1;i++){
      ans = min(ans,arr[i]+a - arr[i+1]);
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