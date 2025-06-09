#include <bits/stdc++.h>

using namespace std;

#define PI (3.141592653589)
#define M 1000000007
#define pb push_back
#define f first
#define s second
#define rep(i,j) for(int i = 0; i<j; i++)
#define rrep(i,j) for(int i = j; i>=0; i--)
#define all(x) x.begin(), x.end()
#define print(x) cout << x << endl
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
#define pm cout<<"-1"<<endl

//Typedef
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef map<int,int> mii;
typedef set<int,int> sii;

// Debug Overloads
#ifdef localenv
#define debug(x) _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.f); cerr << ","; _print(p.s); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

// Operator Overloads
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v){for (auto &it : v)cin >> it;return istream;}
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }

struct DPResult {
    int match;
    set<pi> opt;
};

int f(int n, const vi& a, const vi& b) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return a[0] == b[0];
    }

    vector<DPResult> dp(n);
    dp[n - 1] = {a[n - 1] == b[n - 1], {{a[n - 1], b[n - 1]}}};
    for (int i = n - 2; i >= 0; --i) {
        int pp = dp[i + 1].match;
        const auto& po = dp[i + 1].opt;

        int cm = -1;
        set<pair<int, int>> co;

        for (const auto& prev : po) {
            vpi cand;
            cand.pb({a[i], b[i]});
            cand.pb({prev.s, b[i]});
            cand.pb({a[i], prev.f});
            cand.pb({prev.s, prev.f});

            for (const auto& p : cand) {
                int mach = pp + (p.f == p.s);
                if (mach > cm) {
                    cm = mach;
                    co.clear();
                    co.insert(p);
                } else if (mach == cm) {
                    co.insert(p);
                }
            }
        }
        dp[i] = {cm, co};
    }
    return dp[0].match;
}

void solve() {
    int n;
    cin >> n;
    vi a(n), b(n);
    cin >> a >> b;

    int maxi = 0;
    maxi = f(n, a, b);
    for (int k = 0; k < n; ++k) {
        if (n - 1 == 0) {
            maxi = max(maxi, 0);
            continue;
        }
        vector<int> arem, brem;
        arem.reserve(n - 1);
        brem.reserve(n - 1);
        for (int i = 0; i < n; ++i) {
            if (i != k) {
                arem.pb(a[i]);
                brem.pb(b[i]);
            }
        }
        maxi = max(maxi, f(n - 1, arem, brem));
    }

    cout << maxi << endl;
}

int main()
{
ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t; 
    // t = 1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

