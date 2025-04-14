#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;

int main() {
    string s;
    cin >> s;
    for (char c : s) {
        if (c == 'w' || c == 'm') {
            cout << 0 << endl;
            return 0;
        }
    }

    vector<ll> fib(s.size() + 2, 0);
    fib[0] = fib[1] = 1;
    for (int i = 2; i < fib.size(); ++i)
        fib[i] = (fib[i - 1] + fib[i - 2]) % M;

        // for(auto i:fib){
        //     cout << i <<" " ;
        // }
        // cout << endl;

    ll ans = 1;
    for (int i = 0; i < s.size();) {
        if (s[i] == 'u' || s[i] == 'n') {
            char ch = s[i];
            int j = i;
            while (j < s.size() && s[j] == ch) j++;
            int len = j - i;
            ans = (ans * fib[len]) % M;
            i = j;
        } else {
            i++;
        }
    }

    cout << ans << endl;
    return 0;
}
