#include <bits/stdc++.h>

using namespace std;

// Debug Overloads
void solve(){
    int a,b;
    cin >> a >> b;
    int count = INT_MAX;
    int m = 32;
    int d = b;
    if(b == 1) d++;
    while(m--){
        int temp = a;
        int k = 0;
        // cout << temp <<" ";
        while(temp > 0){
            // cout << temp <<" ";
            temp /= d;
            k++;
        }
        // cout << k <<" " << d <<" " << b <<"--";
        int val = d+k-b;
        // cout << val <<" " << count <<" -- ";
        count = min(count,val);
        // cout << count <<" ";
          d+= 1;
    }

    cout << count << endl;
}

signed main()
{
    int t; 
    // t = 1;
    cin>>t;
    while(t--)
    {
        solve();
    }
}

