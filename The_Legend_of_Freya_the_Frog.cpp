#include <bits/stdc++.h>

using namespace std;
void solve(){
    int x,y,k; cin >> x >> y >> k;

    int s1 = y/k;
    if(y%k != 0) s1++;
     int s2 = x/k;
    if(x%k != 0) s2++;
     if(s2 > s1) cout << max(s1,s2)*2-1 << endl;

    else cout << max(s1,s2)*2 << endl;

}

int main()
{
    int t; 
    // t = 1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

