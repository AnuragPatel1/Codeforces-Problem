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

pi f(int&n ,int&m, vvi&arr, vector<vpi>&dp, int i, int xx){
    // base cse
    if(i == n){
        if(xx == 0) return {0,-1};
        else return {1,-1};
    }

    if(dp[i][xx].f != -1) return dp[i][xx];

    dp[i][xx].f = 0;
    for(int j = 0; j < m; j++){
        if(f(n,m,arr,dp,i+1,xx^arr[i][j]).f){
            dp[i][xx] = {1,j};
            break;
        }
    }
    return dp[i][xx];

}

void solve(){
   int n,m; cin >> n >> m;
   vector<vi>arr(n,vi(m));
   rep(i,n) 
      rep(j,m) cin >> arr[i][j];

   vector<vpi>dp(n+1,vpi(1024,{-1,-1}));
   int i = 0;
   int xx = 0;
   pi p = f(n,m,arr,dp,i,xx);
   if(p.f == 0){
    print("NIE"); return;
   }
   print("TAK");
   i = 0, xx = 0;
   while(i < n){
     int elem = dp[i][xx].s;
     cout << elem+1 <<" ";
     int newRow = i+1;
     int newXor = xx ^ arr[i][elem];
     i = newRow;
     xx = newXor;
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

