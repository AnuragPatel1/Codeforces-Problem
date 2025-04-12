#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    vector<int> color(n);
    vector<int> result(n, -1);
    string s;
    
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        p[i]--;
    }
    
    cin >> s;
    for (int i = 0; i < n; ++i) {
        color[i] = (s[i] == '0') ? 1 : 0; 
    }
    
    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            int count_black = 0;
            vector<int> cycle;
            int current = i;

            while (!visited[current]) {
                visited[current] = true;
                cycle.push_back(current);
                count_black += color[current];
                current = p[current];
            }
            
            for (int idx : cycle) {
                result[idx] = count_black;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}