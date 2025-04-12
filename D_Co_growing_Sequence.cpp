#include <bits/stdc++.h>
using namespace std;

#define int long long


void solve() {
    int n; cin >> n;
    if( n==1){
        int num; cin >> num;
        cout << 0 << endl;
        return;
    }
    
    int ans = 0;
    int prev ;
    cin >> prev;
    cout << 0 << " ";
    for(int i = 0; i < n-1; i++){
       int curr; cin >> curr;
    //    cout << curr <<"=" << prev <<" ";
       int temp = curr;
       int cal = 0;
       while(prev > 0){
           int chk1 = prev % 2;
           int chk2 = temp % 2;
           if((chk1 != chk2) && chk1 == 1){
               ans += (1 << cal);
            //    cout << ans <<" ";
           }
           prev = prev/2;
           temp = temp/2;
           cal++;
       }
       cout << ans <<" ";
       prev = ans^curr;
       ans = 0;
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