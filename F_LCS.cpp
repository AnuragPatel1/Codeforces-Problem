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

int f(string &s, string &t, int&n, int&m, int i, int j, vvi&dp){
    // base case 
    if(i >= n || j >= m) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    // when s[i] == t[j] => we have to include it into the answer
    if(s[i] == t[j]) return dp[i][j] = 1 + f(s,t,n,m,i+1,j+1,dp);
    
    // otherwise when both are not equal then we took the maximum from it
    return dp[i][j] = max(f(s,t,n,m,i+1, j,dp), f(s,t,n,m,i,j+1, dp));

}

void solve(){
    string s,t; cin >> s >> t;
    int n=s.length(), m = t.length();

    vector<vi>dp(n, vi(m, -1));
    int i = 0 , j = 0;
    int length = f(s,t,n,m,i,j,dp);
    
     int x = 0,y= 0 ;
    while(x < n && y < m){
        if(s[x] == t[y]){
            cout << s[x] ;
            x++, y++;
        }
        else{
            if((x+1) < n && dp[x][y] == dp[x+1][y]) x++;
            else if((y+1) < m && dp[x][y] == dp[x][y+1]) y++;
            else break;
        }
    }

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

