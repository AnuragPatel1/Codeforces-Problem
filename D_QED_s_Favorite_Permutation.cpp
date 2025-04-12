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
    int q; cin >> q;
    // vi arr(n);
    vi t(n);
    cin >> t[0];
    for(int i=1; i < n; i++){
        int num; cin >> num;
        if(num > t[i-1]) t[i] = num;
        else t[i] = t[i-1];
    }
    string s; cin >> s;
    
    vector<bool>chk(n,false);
    int count= 0;
    rep(i,n){
        if(s[i] == 'L' && s[i+1] == 'R' && t[i] > i+1) {chk[i] = true; count++;}
    }

//  debug(count);

    while(q--){
        int k; cin >> k; k--;
        // bool ans = true;
        // debug(chk );
        if((chk[k] && s[k] == 'L') || (s[k] =='R' && (k-1 >= 0) &&chk[k-1] == true) ){count--; chk[k] = false;}

        if(s[k] == 'R') s[k] = 'L';
        else s[k] = 'R';
        
        if(k < n-1 && s[k] == 'L' && s[k+1] == 'R' && t[k] > k+1) {count++; chk[k] = true;}
        if(k > 0 && s[k] == 'R' && s[k-1] == 'L' && t[k-1] > k) {count++; chk[k-1] = true;}

        // if(q == 0) debug(chk); 

        if(count) NO;
        else YES;


        // rep(i,n-1){
        //     if(s[i] == 'L' && s[i+1] == 'R' && t[i] > i+1){
        //         ans = false; break;
        //     }
        //     // else YES;
        // }
      
    //   if(ans) YES;
    //   else NO;



    }


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
