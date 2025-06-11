#include <bits/stdc++.h>

using namespace std;

#define PI (3.141592653589)
#define M 998244353
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

ll cal(ll b){
    ll a = 2;
    ll ans = 1;
    while(b){
        if(b&1) ans = (ans * a)%M;
        a = (a*a)%M;
        b/=2;
    }
    return ans%M;
}

void solve(){
   ll n; cin >> n;
   vl a(n); cin >> a;
   vl b(n); cin >> b;

   vpl ans;
   ll maxA = -1, maxAindex = -1;
   ll maxB = -1, maxBindex = -1;
   ll i = 0;
   while(i < n){
      if(maxA < a[i]){
          maxA = a[i]; maxAindex = i;
      }
      if(maxB < b[i]){
        maxB = b[i] ; maxBindex = i;
      }
      
      if(maxA > maxB){
          ans.pb(make_pair(b[i-maxAindex], a[maxAindex]));
      }
      else if(maxB > maxA){
        ans.pb(make_pair(a[i-maxBindex], b[maxBindex]));
      }
      else{ 
        if(b[i-maxAindex] > a[i-maxBindex] )
        ans.pb({maxA,b[i-maxAindex]});
        else ans.pb({maxB,a[i-maxBindex]});
      }
      i++;
   }

//    debug(ans);

   for(auto i:ans){
       int a = (cal(i.first) + cal(i.second))%M;
       cout << a <<" ";
   }
   cout << endl;


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

