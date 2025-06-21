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

void solve(){
   int n; cin >> n;
   vi a(n),b(n); cin >> a >> b;
   vpi ans;
   int x = 0;
   while(x < n){
     if(a[x] <= n && b[x] > n) x++;
     else if(a[x] > n && b[x] <= n) x++;
     else if(a[x] <= n && b[x] <= n){
        int d = x;
        while((d+1) < n && a[d+1] <= n){
           d++;
        }
        while(d >= x){
            swap(a[d], a[d+1]);
            ans.pb({1,d+1});
            d--;
        }
     }
     else{
        int d = x;
        while((d+1) < n && b[d+1] > n){
           d++;
        }
        while(d >= x){
            swap(a[d], a[d+1]);
            ans.pb({2,d+1});
            d--;
        }
     }
   }

   for(int i = 0; i < n; i++){
     if(a[i] > b[i]){
        swap(a[i], b[i]);
        ans.pb({3,i+1});
     }
   }
   
   for(int i = 0; i < n; i++){
      if(a[i] == (i+1)) continue;
      for(int j = (n-1); j > i; j--){
         if(a[j] == (i+1)){
            swap(a[j], a[j-1]);
            ans.pb({1,j});
         }
      }
   }
   
   for(int i = 0; i < n; i++){
       if(b[i] == (n+i+1)) continue;
       for(int j = (n-1); j > i; j--){
           if(b[j] == (n+i+1)){
               swap(b[j], b[j-1]);
               ans.pb({2,j});
            }
        }
    }
    // debug(a); debug(b);
   cout << ans.size() << endl;
   for(auto i:ans){
      cout << i.f <<" " << i.s << endl;
   }

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

