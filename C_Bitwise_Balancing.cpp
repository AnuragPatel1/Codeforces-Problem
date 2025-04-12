#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int t;
    cin>>t;
    while(t--) {
        ll b,c,d;
        cin>>b>>c>>d;
        ll num = b ^ d;
        if((num|b)-(num&c) == d) {
            cout<<num<<endl;
        }
        else {
            cout<<-1<<endl;
        }
    }
    return 0;
}