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

bool safe(ll mid,vl&pos,vl&neg){
    // debug(pos); debug(neg);
    ll i = 0;
    ll j = 0;
    ll sum = 0;
    ll ans = 0;
    while(i < pos.size() && j < neg.size()){
        sum+=pos[i];
        ans = max(sum,max(ans,pos[i]));
        // debug(ans);
         i++;
        while(j < neg.size() && i < pos.size() && (sum+pos[i]) > mid){
            sum += neg[j];
            j++;
            if(sum < 0) sum = 0;
        }
    }
    
     if(sum < 0) sum = 0;
    while(i < pos.size()){
        sum += pos[i];
        ans = max(sum,max(ans,pos[i]));
        i++;
    }
    ans = max(sum,ans);
    if(ans <= mid) return true;
    else return false;
}

void solve(){
    ll n; cin >> n;
    vl arr(n); cin >> arr;
    vl pos,neg;
    for(auto i:arr){
        if(i < 0)neg.pb(i);
        else pos.pb(i);
    }
    vl pre;
    if(pos.size() == 0){
        print(0); return;
    }
   
    ll i = 0;
    ll j = 1e18;
    ll ans=0;
    while(i <= j){
        ll mid = (i+j)/2;
        if(safe(mid,pos,neg)){
            ans = mid;
            j = mid-1;
        }
        else i = mid+1;
    }

    // debug(safe(2,pos,neg));
    ll t = 0;
    ll chk = max(t,ans);
    print(chk);
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

