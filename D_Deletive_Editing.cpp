#include <bits/stdc++.h>
using namespace std;

#define int long long int



void solve() {
    string s; cin >>s;
    string t; cin >> t;
    vector<pair<int,char>>p;
    int len1 = s.length();
    int len2 = t.length();
    
    // cout << len1 <<" " << len2 <<" ";

    int i = len1-1;
    int j = 0;
    while(i >= 0){
        if(s[i] == t[j]){
            s[i] = '-';
            p.push_back({i,t[j]});
            i = len1-1;
            // cout << i <<" ";
            j++;
            if( j == len2) break;
        }
        else i--;
    }

    // for(auto i : p) cout << i.first <<"=" << i.second <<" ";

    if(p.size() != len2){
        cout << "NO" << endl; return;
    }

    sort(p.begin(),p.end());
    j = 0;

    // for(auto i : p) cout << i.first <<"=" << i.second <<" ";

    for(auto i : p){
        if(i.second == t[j])j++;
        else {cout <<"NO" << endl; return;}
    }
    cout << "YES" << endl;
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