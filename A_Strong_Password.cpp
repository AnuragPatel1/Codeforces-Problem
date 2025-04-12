#include <bits/stdc++.h>
using namespace std;

#define int long long int

void solve() {
   string s; cin >> s;
   vector<char>arr(2);
   arr[0] = 'a';
   arr[1] = 'b';
   bool flag = true;
   for(int i = 0; i < s.length()-1;i++){
       if(flag && s[i] == s[i+1]){
        cout <<s[i] ;
        if(s[i] == arr[0]) cout << arr[1];
        else cout << arr[0];
        flag = false;
       }
       else cout << s[i];
   }
   if(flag){
       char temp = s[s.length()-1];
       cout << temp;
       if(temp != arr[0]) cout << arr[0];
       else cout << arr[1]; 
   }
   else cout << s[s.length()-1];
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