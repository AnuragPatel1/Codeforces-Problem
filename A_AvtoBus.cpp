#include <bits/stdc++.h>
using namespace std;

#define int long long int



void solve() {
    int n ; cin >> n;
    if(n & 1 || n <= 2){
        cout << -1 << endl;
        return ;
    }
    int rem = n % 12;
    int mini =  (n /12)*2 ;
    int maxi = (n/12)*3;
    if(rem == 10){
        mini += 2;
        maxi += 2;
    }
    else if(rem == 8){
        mini += 2;
        maxi += 2;
    }
    else if(rem == 6 || rem == 4){
        mini ++;
        maxi++;
    }
    else if(rem == 2){
        mini++ ;
    }
    
    cout << mini <<" " << maxi << endl;
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