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

ll f(string&s, ll &n, ll i, ll issame, ll count, vector<vvl>&dp){
    if(i == n) return 1;
    if(dp[i][issame][count] != -1) return dp[i][issame][count];
    ll ans = 0;
    for(ll j = '0' ; j <= (issame ? s[i]:'9'); j++){
        if(j == '0'){
            ans += f(s,n,i+1,issame && s[i] == j , count,dp);
        }
        else if(count <= 2) ans += f(s,n,i+1,issame && s[i] == j, count+1, dp);
    }
    return dp[i][issame][count] = ans;
}

bool chk(string&s){
    ll count = 0;
    for(auto i:s){
        if(i != '0') count++;
    }
    if(count <= 3) return true;
    else return false;
}

void solve(){
    ll a,b; cin >> a >> b;
    string s = to_string(a);
    string t = to_string(b);
    ll n = s.size();
    ll m = t.size();
    vector<vvl>dp1(m+1,vvl(2,vl(m+1, -1)));
    vector<vvl>dp2(n+1,vvl(2,vl(n+1, -1)));

    ll ans = f(t,m,0,1,0,dp1) - f(s,n,0,1,0,dp2) + chk(s);
    print(ans);
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

