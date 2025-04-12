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
    vector<vector<int>>arr(n, vector<int>(n,0));
    
    rep(i,n){
        string s; cin >> s;
        rep(j,n){
            if(s[j] == '1') arr[i][j] = 1;
        }
    }

    // debug(arr);

    if(n == 1){
        cout << 0 << endl; return;
    }

    vector<vector<int>>arr2;
    rep(i,n){
        vi temp;
        rrep(j,n-1){
           temp.pb(arr[j][i]);
        }
        arr2.pb(temp);
    }

    // debug(arr2);

    vector<vector<int>>arr3;
    rep(i,n){
        vi temp;
        rrep(j,n-1){
           temp.pb(arr2[j][i]);
        }
        arr3.pb(temp);
    }

    // debug(arr3);

      vector<vector<int>>arr4;
      rep(i,n){
          vi temp;
          rrep(j,n-1){
             temp.pb(arr3[j][i]);
          }
          arr4.pb(temp);
      }

    //   debug(arr4);

      int ans = 0;
      rep(i,(n+1)/2){
        rep(j,(n)/2){
            int c = 0,d=0;
            if(arr[i][j] == 0) c++;
            else d++;
            if(arr2[i][j] == 0) c++;
            else d++;
            if(arr3[i][j] == 0) c++;
            else d++;
            if(arr4[i][j] == 0) c++;
            else d++;
            ans += min(c,d);
        }
      }
    print(ans);
}

int main()
{
    int t; 
    // t = 1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

