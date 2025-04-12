#include <bits/stdc++.h>

using namespace std;

#define PI (3.141592653589)
#define M 1000000007
#define pb push_back
#define f first
#define s second
#define rep(i, j) for (int i = 0; i < j; i++)
#define rrep(i, j) for (int i = j; i >= 0; i--)
#define all(x) x.begin(), x.end()
#define print(x) cout << x << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define pm cout << "-1" << endl

// Typedef
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef map<int, int> mii;
typedef set<int, int> sii;

// Debug Overloads
#ifdef localenv
#define debug(x) _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }

template <class T, class V> void _print(pair<T, V> p);
template <class T> void _print(vector<T> v);
template <class T> void _print(set<T> v);
template <class T> void _print(multiset<T> v);
template <class T, class V> void _print(map<T, V> v);
template <class T, class V> void _print(pair<T, V> p) { cerr << "{"; _print(p.f); cerr << ","; _print(p.s); cerr << "}"; }
template <class T> void _print(vector<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(set<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(multiset<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(map<T, V> v) { cerr << "[ "; for (auto i : v) { _print(i); cerr << " "; } cerr << "]"; }

// Operator Overloads
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v) { for (auto &it : v) cin >> it; return istream; }
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }

map<pair<string, vector<bool>>, int> dp;

int ans(vector<bool>& visited, vector<string>& s, int& n, string str) {
    if (dp.find({str, visited}) != dp.end()) {
        return dp[{str, visited}];
    }

    int count = 0;
    rep(i, n) {
        if ((str.find(s[i]) != string::npos) && visited[i] == false) {
            visited[i] = true;
            string tut = str;
            int ind = str.find(s[i]);
            int len = s[i].length();
            str.erase(ind, len);
            count = max(count, 1 + ans(visited, s, n, str));
            str = tut;
            visited[i] = false;
        }
    }
// debug(dp);
    return dp[{str, visited}] = count;
}

void solve() {
    int n; cin >> n;
    vector<string> s(n);
    rep(i, n) {
        cin >> s[i];
    }

// debug(s);

    vector<bool> visited(n, false);
    string str; cin >> str;
    // debug(str);
    int count = ans(visited, s, n, str);
    // debug(count);
    print(count);
}

int main() {
    int t;
    t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
