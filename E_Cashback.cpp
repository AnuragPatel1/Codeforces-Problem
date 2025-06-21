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

ll f(ll&n, vl&arr, ll i,ll k, vl&dp){
    if(i >= n) return 0;
    if(dp[i] != -1) return dp[i];
    ll ans = 0;
    ans = max(arr[i] + f(n,arr,i+k,k,dp), f(n,arr,i+1,k,dp));
    return dp[i] = ans;
}

void solve(){
    ll n,k; cin >> n >> k;
    vl a(n); cin >> a;
    if(n < k){
        ll ans = accumulate(all(a),0*1ll);
        print(ans); return;
    }
    vl arr;
    multiset<ll>m;
    rep(i,k)m.insert(a[i]);
    arr.pb(*m.begin());
    ll i = k;
    ll j = 0;
    while(i < n){
        m.erase(m.find(a[j++]));
        m.insert(a[i++]);
        arr.pb(*m.begin());
    }

    // debug(arr);

    n = arr.size();
    vl dp(n+1, -1);
    ll d = f(n,arr,0,k,dp);
    // debug(d);
    ll ans = accumulate(all(a),0*1ll) - d;
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

