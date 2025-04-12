#include <bits/stdc++.h>
using namespace std;

#define int long long int

bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;

    return (ceil(log2(n)) == floor(log2(n)));
}

void solve() {
   int n; cin >> n;
   if(n == 2){
    cout <<"NO" << endl;
    return;
   }
   int num = sqrt(n);
   if(isPowerOfTwo(n))
   cout << "NO" << endl;
   else cout << "YES" << endl;
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