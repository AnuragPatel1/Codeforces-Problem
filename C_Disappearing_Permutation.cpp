#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    vector<int> d(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }

    vector<int> freq(n + 2, 0);
    for (int v : p) {
        freq[v]++;
    }

    long long sum_B = 0;
    for (int v = 1; v <= n; ++v) {
        sum_B += max(0, freq[v] - 1);
    }

    vector<bool> S_set(n + 2, false);
    long long sum_A = 0;
    vector<int> ans;

    for (int i = 0; i < n; ++i) {
        int j = d[i]; // j is 1-based
        int v = p[j - 1]; // p is 0-based

        // Update freq[v] and sum_B
        int old = max(0, freq[v] - 1);
        freq[v]--;
        int new_val = max(0, freq[v] - 1);
        sum_B += (new_val - old);

        // Check if v is a position in S_set (1-based)
        if (v <= n && S_set[v]) {
            sum_A--;
        }

        // Add j to S_set if not present
        if (!S_set[j]) {
            S_set[j] = true;
            sum_A += freq[j];
        }

        // Compute answer
        ans.push_back((i + 1) + sum_A + sum_B);
    }

    for (int x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
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