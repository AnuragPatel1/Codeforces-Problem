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

// if ans = -1 set it to 0;
void solve(){
   int n,m; cin >> n >> m;
   vvi arr(n, vi(m)); cin >> arr;
   int maxi = 0;
   rep(i,n) rep(j,m) maxi = max(maxi, arr[i][j]);
   vvi temp = arr;
   int r = -1;
   for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
         if(arr[i][j] == maxi){
            rep(k,m) arr[i][k] -= 1;
            r = i;
            break;
         }
      }
      if(r != -1) break;
   }
   maxi = 0;
   rep(i,n) rep(j,m) maxi = max(maxi, arr[i][j]);

   bool chk = false;
    for(int i = 0; i < n; i++){
        // if(i == r) continue;
      for(int j = 0; j < m; j++){
         if(arr[i][j] == maxi){
            rep(k,n) if(k != r) arr[k][j] -= 1;
            chk = true;
            break;
         }
      }
      if(chk) break;
   }

int ans = -1;
rep(i,n) rep(j,m) ans = max(ans, arr[i][j]);

// debug(arr);

arr = temp;

maxi  = 0;
int c = -1;
rep(i,n) rep(j,m) maxi = max(maxi, arr[i][j]);
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
         if(arr[i][j] == maxi){
            rep(k,n) arr[k][j] -= 1;
            c = j;
            break;
         }
      }
      if(c != -1) break;
   }

chk = false;   
rep(i,n) rep(j,m) maxi = max(maxi, arr[i][j]);
 for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        //  if(j == c) continue;
         if(arr[i][j] == maxi){
            rep(k,m) if(k != c) arr[i][k] -= 1;
            chk = true;
            break;
         }
      }
      if(chk) break;
   }

//    debug(arr);
   maxi = 0;
   rep(i,n) rep(j,m) maxi = max(maxi, arr[i][j]);
   ans = min(ans,maxi);
   ans = ans==-1 ? 0 : ans;
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

