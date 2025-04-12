#include <bits/stdc++.h>
using namespace std;

#define int long long

bool root(int n){
    int temp =(sqrt(n));
    if(temp*temp != n) return false;
    return true;
}


void solve() {
  int n; cin >>n;
  string s; cin >>s;
  if(n == 4 && s == "1111"){
    cout << "Yes" << endl;
    return;
  }
  if(root(n) == false){
    cout << "No" << endl;
    return;
  }
else{
    
    int zero = 0;
    for(auto i : s){
        if(i == '0') zero++;
    }
    if(zero != (sqrt(n)-2)*(sqrt(n)-2)){
        cout <<"No" << endl;
        return;
    }
    int i = 0;
    int j = 0;
    while(i <= j){
        if(s[i] != s[j]){
            cout << "No" << endl;
            return;
        }
        i++; j--;
    }
   cout <<"Yes" << endl;
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