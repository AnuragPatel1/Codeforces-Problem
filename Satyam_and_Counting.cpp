#include <bits/stdc++.h>

using namespace std;



void solve(){
    int n; cin >> n;
    map<int,int>m1;
    map<int,int>m2;
    for(int i = 0; i < n; i++){
       int a,b; cin >> a >>b;
       if(m1.find(a) != m1.end())m1[a]++;
       else m1[a] = 1;

        if(m2.find(b) != m2.end())m2[b]++;
       else m2[b] = 1;
    }
    
    int ans = 0;
    for(auto i : m1){
        if(i.second == 2) ans++;
    }
    int count = INT_MAX;
    for(auto i : m2) count = min(i.second,count);
   
   cout << ans*2*count << endl;
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

