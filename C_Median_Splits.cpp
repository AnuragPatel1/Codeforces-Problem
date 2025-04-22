
#include <bits/stdc++.h>
using namespace std;

long long get_median(vector<long long>& arr, int start, int end) {
    vector<long long> sub(arr.begin() + start, arr.begin() + end + 1);
    sort(sub.begin(), sub.end());
    int m = sub.size();
    return sub[(m + 1) / 2 - 1];
}

void solve() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool found = false;
    for (int l = 0; l < n - 2; l++) {
        for (int r = l + 1; r < n - 1; r++) {
            vector<long long> medians;
            medians.push_back(get_median(a, 0, l));
            medians.push_back(get_median(a, l + 1, r));
            medians.push_back(get_median(a, r + 1, n - 1));
            sort(medians.begin(), medians.end());
            if (medians[1] <= k) {
                found = true;
                break;
            }
        }
        if (found) break;
    }

    cout << (found ? "YES" : "NO") << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}