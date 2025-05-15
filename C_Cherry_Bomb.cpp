#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        ll x = -1;
        bool valid = true;
        for (int i = 0; i < n; ++i) {
            if (b[i] != -1) {
                ll curr_x = a[i] + (ll)b[i];
                if (x == -1) {
                    x = curr_x;
                } else {
                    if (curr_x != x) {
                        valid = false;
                        break;
                    }
                }
            }
        }
        if (!valid) {
            cout << 0 << '\n';
            continue;
        }
        if (x != -1) {
            for (int i = 0; i < n; ++i) {
                if (b[i] == -1) {
                    ll bi = x - a[i];
                    if (bi < 0 || bi > k) {
                        valid = false;
                        break;
                    }
                }
            }
            cout << (valid ? 1 : 0) << '\n';
        } else {
            ll low = 0;
            for (int num : a) {
                if (num > low) low = num;
            }
            ll high = 1e18;
            for (int num : a) {
                ll current = (ll)num + k;
                if (current < high) high = current;
            }
            if (low > high) {
                cout << 0 << '\n';
            } else {
                cout << high - low + 1 << '\n';
            }
        }
    }
    return 0;
}