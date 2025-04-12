#include <bits/stdc++.h>
using namespace std;

#define int long long int


string reorderString(string s) {
    int n = s.length();
    vector<int> freq(26, 0);
    
    for (char c : s) {
        freq[c - 'a']++;
    }

    vector<pair<int, char>> chars;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            chars.push_back({freq[i], 'a' + i});
        }
    }

    sort(chars.rbegin(), chars.rend());

    string result(n, ' ');
    int index = 0;

    for (auto &p : chars) {
        while (p.first > 0 && index < n) {
            result[index] = p.second;
            p.first--;
            index += 2;
        }
    }
    
    // dummy()

    index = 1;
    for (auto &p : chars) {
        while (p.first > 0 && index < n) {
            result[index] = p.second;
            p.first--;
            index += 2;
        }
    }
    
    for (int i = 2; i < n; i++) {
        if (result[i] == result[i-1] && result[i-1] == result[i-2]) {
            for (int j = i + 1; j < n; j++) {
                if (result[j] != result[i] && (j == n - 1 || result[j] != result[i+1])) {
                    swap(result[i], result[j]);
                    break;
                }
            }
        }
    }
    
    return result;
}



void solve() {
  int n; cin >> n;
  string s; cin >> s;
  string ans = reorderString(s);
  cout << ans << endl;
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


