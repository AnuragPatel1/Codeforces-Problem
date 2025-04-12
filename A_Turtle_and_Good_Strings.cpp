#include <bits/stdc++.h>
using namespace std;

#define int long long int

int count(string s,int n){
    int ans = 0;
    if(n < 2) return 0;
    for(int i = 0; i < n-1;i++){
         if(s[i] != s[i+1]) ans++;
    }
    return ans;
}

void solve() {
    int n; cin >> n; 
    string s; cin >> s;
    int ans = 0;
    int flag = 0;
    // cout << "hi" <<" ";
    while(n > 2){
        int i = 0;
        while(i < n){
            // cout << i <<" ";
        if(s[i] == s[i+1]){
            s.erase(i,1);
            ans += count(s,n-1);
            n--;
        }
        i++;
        if(i==n){
            s.erase(i-1,i);
            ans += count(s,n-1);
            n--;
        }
      }
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