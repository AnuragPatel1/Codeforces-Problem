#include <bits/stdc++.h>
using namespace std;


void solve() {
   int dx[4] = {1,-1,0,0};
   int dy[4] = {0,0,-1,1};
   
   int n; cin >> n;
   int a,b; cin >> a >> b ;
   pair<int,int>start = make_pair(0,0);
   string s; cin >> s;
   
   vector<pair<int,int>>dist(n);
   for(int i = 0; i < n; i++){
       if(s[i] == 'L'){
           dist[i] = make_pair(start.first-1,start.second);
           start.first = start.first -1;
       }
       else if(s[i] == 'R'){
           dist[i] = make_pair(start.first+1,start.second);
           start.first = start.first +1;
       }
       else if(s[i] == 'U'){
           dist[i] = make_pair(start.first,start.second+1);
           start.second += 1;
       }
      else  if(s[i] == 'D'){
           dist[i] = make_pair(start.first,start.second-1);
           start.second -= 1;
       }
   }
   
   int count = 1;
   for(auto i : dist){
    //   cout << i.first << "-" << i.second <<" ";
       int c = abs(a-i.first) + abs(b - i.second);
       if(count > n) break;
       if(c == count ){
        //   cout << c << endl;
           cout <<"YES" << endl;
           return;
       }
       count++;
   }
   cout << "NO" << endl;
   return;
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