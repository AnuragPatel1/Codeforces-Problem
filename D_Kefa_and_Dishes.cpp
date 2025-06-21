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

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    
    vl arr(n);
    for (ll i = 0; i < n; ++i) cin >> arr[i];
        vector<vector<ll>> bonus(n, vl(n, 0));
    for (ll i = 0; i < k; ++i) {
        ll x, y, c;
        cin >> x >> y >> c;
        --x; --y;
        bonus[x][y] = c;
    }
    vvl dp(1 << n, vl(n, 0));
    for (ll i = 0; i < n; ++i) {
        dp[1 << i][i] = arr[i];
    }
    for (ll mask = 0; mask < (1 << n); ++mask) {
        for (ll last = 0; last < n; ++last) {
            if (!(mask & (1 << last))) continue; 
            if (__builtin_popcount(mask) > m) continue;

            for (ll nxt = 0; nxt < n; ++nxt) {
                if (mask & (1 << nxt)) continue; 

                ll new_mask = mask | (1 << nxt);
                ll new_satisfaction = dp[mask][last] + arr[nxt] + bonus[last][nxt];
                dp[new_mask][nxt] = max(dp[new_mask][nxt], new_satisfaction);
            }
        }
    }

    ll ans = 0;
    for (ll mask = 0; mask < (1 << n); ++mask) {
        if (__builtin_popcount(mask) == m) {
            for (ll last = 0; last < n; ++last) {
                ans = max(ans, dp[mask][last]);
            }
        }
    }

    print(ans);
}

int main()
{
ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t; 
    t = 1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

