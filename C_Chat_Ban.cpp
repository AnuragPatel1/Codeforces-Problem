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

// (mid/2) * (2*(n-1)+ 1 - mid)

bool chk(bool flag, ll n, ll x, ll mid){
    ll sum = 0;
    if(!flag){
         sum = ((mid) * (2*(n-1)+ 1 - mid))/2;
        //  cerr << "sum is :  " << sum << endl;
    }
    else  sum = ((mid+1)*mid)/2;
    if(sum < x) return true;
    return false;
}

void solve(){
    ll n,x; cin >> n >> x;
    bool flag = true;
    ll i = 1;
    ll j = n;
    ll ans = 0;
    while(i <= j){
        ll mid = (i+j)/2;
        if(chk(flag,n,x,mid)){
            ans = mid;
            i = mid+1; 
        }
        else j = mid-1;
    }
    ans++;
    ans = min(ans,n);
    // // debug(ans);

    ll ans2 = 0;
    x -= (((ans+1)*ans)/2);
    i = n-1;
    // // debug(i);
    // cerr << x <<" " << i << endl;

    if(x > 0 && i > 0){
         flag = false;
        i = 1;
        j = n-1;
        while(i <= j){
            ll mid = (i+j)/2;
            if(chk(flag,n,x,mid)){
                ans2 = mid;
                i = mid +1;
            }
            else j = mid-1;
        }
        ans2++;
        ans2 = min(ans2,n-1);
    }

    // debug(chk(false,6,10,2));

    cout << (ans+ans2) << endl;


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

