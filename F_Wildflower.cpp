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
typedef set<int> si;

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
template <class T, class V> void _print(map <T, V> v);

template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.f); cerr << ","; _print(p.s); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

template<typename T>
istream& operator>>(istream &istream, vector<T> &v){for (auto &it : v)cin >> it;return istream;}
template<typename T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }

vvi adj;
vi sz;

void dfs_size(int u, int p) {
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v != p) {
            dfs_size(v, u);
            sz[u] += sz[v];
        }
    }
}

ll dfs_ways(int u, int p) {
    if (adj[u].size() == 1 && u != 1) return 1;

    mii sz_counts;
    ll cur = 1, perm = 1;

    for (int v : adj[u]) {
        if (v != p) {
            ll sub = dfs_ways(v, u);
            if (sub == 0) return 0;
            cur = (cur * sub) % M;
            sz_counts[sz[v]]++;
        }
    }

    for (mii::iterator it = sz_counts.begin(); it != sz_counts.end(); ++it) {
        int val = it->f;
        int cnt = it->s;
        if (cnt > 2) return 0;
        if (cnt == 2) perm = (perm * 2) % M;
    }

    ll ch = (u == 1 ? 1 : 2);
    cur = (cur * perm) % M;
    cur = (cur * ch) % M;

    return cur;
}

void solve(){
    int n;
    cin >> n;
    adj.assign(n + 1, vi());
    sz.assign(n + 1, 0);

    rep(i, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs_size(1, 0);
    cout << dfs_ways(1, 0) << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t; 
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
