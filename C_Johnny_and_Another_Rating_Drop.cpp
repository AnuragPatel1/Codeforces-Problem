#include <bits/stdc++.h>

using namespace std;

#define int long long

int cal(int n,int key){
     if(n <= 0) return 0;
     int s = n/4;
     int ans1 = (3*key + 1)*s;
     if(n % 4 == 1) ans1 += key;
     else if(n % 4 == 2) ans1 += (2*key + 1);
     else if(n % 4 == 3) ans1 += (3*key + 1);

     return (ans1 + cal(s,key+2));
}

void solve(){
    int n; cin >> n;
    cout << cal(n,1) << endl;
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

