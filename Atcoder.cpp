#include<iostream>
using namespace std;

#define int long long

signed main(){
    int t; cin >> t;
    while(t--){
        int n,m; cin>> n >> m;
        int ans = 0;
        if(m&1){
            int a = __builtin_popcountll(m);
             ans = ((m/2)%998244353)*a + a;
        }
        else{
             ans = (n/8)*4;
            if(n % 8 == 4) ans++;
            else if(n % 8 == 5) ans+=2;
            else if(n % 8 == 6) ans+=3;
            else if(n % 8 == 7) ans+=4;
        }
        cout << ans%998244353 << endl;
    }
    return 0;
}