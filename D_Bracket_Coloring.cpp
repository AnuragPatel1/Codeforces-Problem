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
    string s; cin >> s;
    vi arr(n);
    rep(i,n){
        if(!i){
            if(s[i] == ')') arr[i] = -1;
            else arr[i] = 1;
        }
        else {
            if(s[i] == ')') arr[i] = -1+arr[i-1];
            else arr[i] = 1+arr[i-1];
        }
    }
    
    if(arr[n-1] != 0){
        cout << -1 << endl; return;
    }
    
    vi ans;
    if(arr[0] > 0){
        int i = 0;
        while(i < n){
            if(arr[i] > 0){
                ans.pb(1);
            }
            else if(arr[i] < 0){
                ans.pb(2);
            }
            else{
                if(arr[i-1] > 0) ans.pb(1);
                else ans.pb(2);
            }
            i++;
        }
    }
    else{
        int i = 0;
        while(i < n){
            if(arr[i] < 0){
                ans.pb(1);
            }
            else if(arr[i] > 0){
                ans.pb(2);
            }
            else{
                if(arr[i-1] < 0) ans.pb(1);
                else ans.pb(2);
            }
            i++;
        }
    }

    int count = 1;
    for(auto i:ans) count = max(count,i);
    cout << count << endl;
    cout << ans << endl;
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

