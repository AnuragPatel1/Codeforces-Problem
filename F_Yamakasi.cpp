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
   ll n,sum,maxi; cin >> n >> sum >> maxi;
   vl arr(n); cin >> arr;
   ll i = 0;
   vl temp;
   ll ans = 0;
   while(i < n){
       ll cal = 0;
        ll lastIndex = -1;
        while(i < n && arr[i] <= maxi){
             temp.pb(arr[i]);
            if(arr[i] == maxi) lastIndex = cal;
            i++;
            cal++;
        }
        // debug(temp);
        i++;

        if(lastIndex != -1){
                vl org = temp;
                ll size = temp.size();
                for(ll j = 0; j < size; j++){
                    if(j) temp[j] += temp[j-1];
                }
                // debug(temp);
                map<ll,ll>m;

                  ll j = size-1;
                //   cerr << j <<"  " << lastIndex << endl;
                  while(j >= lastIndex) m[temp[j--]]++;
                  lastIndex--;
                //   debug(m);
                //   debug(j);
                  while(j >= 0){
                     while(j >= 0 && org[j] != maxi){
                        ll last = temp[j]+sum;
                        ans += m[last];
                        j--;
                     }
                    //  debug(m);
                     if(j >= 0) ans += m[temp[j]+sum];
                     else ans += m[sum];
                    //  cerr << "ans is :" << ans << endl;
                     while(lastIndex >= 0 && lastIndex >= j) m[temp[lastIndex--]]++;
                     j--;
                  }
                  if(org[0] == maxi) ans += m[sum];

        }
        // debug(ans);
        while(temp.size() > 0) temp.pop_back();
   }
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

