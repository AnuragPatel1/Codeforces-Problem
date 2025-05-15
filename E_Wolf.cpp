#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> p(n + 1);
    vector<int> pos_map(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        pos_map[p[i]] = i;
    }

    while (q--) {
        int l, r, xk;
        cin >> l >> r >> xk;
        int pos = pos_map[xk];
        if (pos < l || pos > r) {
            cout << "-1\n";
            continue;
        }

        int current_l = l, current_r = r;
        int left_count = 0, right_count = 0;
        bool possible = true;

        while (current_l <= current_r) {
            int m = (current_l + current_r) / 2;
            if (m == pos) {
                break;
            }
            if (m < pos) {
                if (p[m] >= xk) {
                    left_count++;
                    if (xk == 1) possible = false;
                }
                current_l = m + 1;
            } else {
                if (p[m] <= xk) {
                    right_count++;
                    if (xk == n) possible = false;
                }
                current_r = m - 1;
            }
        }

        if (!possible) {
            cout << "-1\n";
        } else {
            if (left_count > xk - 1 || right_count > (n - xk)) {
                cout << "-1\n";
            } else {
                cout << left_count + right_count << "\n";
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}