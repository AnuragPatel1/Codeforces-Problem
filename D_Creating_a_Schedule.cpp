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
    int q, n;
    cin >> q >> n;
    vector<int> arr(n);
    for (int &x : arr) cin >> x;

    sort(arr.begin(), arr.end());  // Sorted by floor implicitly

    vector<vector<int>> ans(q, vector<int>(6));

    int half = q / 2;

    // Assign first half: low → high → ...
    for (int i = 0; i < half; ++i){
        for (int j = 0; j < 6; ++j){
            if (j % 2 == 0) ans[i][j] = arr[i];            // low
            else           ans[i][j] = arr[n - 1 - i];      // high
        }
    }

    // Assign second half: high → low → ...
    for (int i = 0; i < half; ++i){
        for (int j = 0; j < 6; ++j){
            if (j % 2 == 0) ans[i + half][j] = arr[n - 1 - i];  // high
            else            ans[i + half][j] = arr[i];          // low
        }
    }

    // Handle extra group if q is odd
    if (q % 2 == 1){
        int i = q - 1;
        for (int j = 0; j < 6; ++j){
            if (j % 2 == 0) ans[i][j] = arr[half];         // middle low
            else            ans[i][j] = arr[n - 1 - half]; // middle high
        }
    }

    // Print result
    for (auto &grp : ans){
        for (int x : grp) cout << x << " ";
        cout << '\n';
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

