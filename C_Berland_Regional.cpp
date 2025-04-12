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
    ll n; cin >> n;
    vl arr1(n); cin >> arr1;
    vl arr2(n); cin >> arr2;
    
    map<ll,vl> m;
    rep(i,n){
        m[arr1[i]].pb(arr2[i]);
    }

    for(auto &i:m){
       vl temp = i.s;
       sort(all(temp));
       reverse(all(temp));
       for(ll j = 1; j < temp.size(); j++){
            temp[j] += temp[j-1];
       }
       i.s = temp;
    }

    mii size;
    for(auto i:m){
        size[i.f] = i.s.size();
    }
    
   vl ans(n,0);
//    for(ll i = 1; i <= n; i++){
//       ll sum = 0;
//       for(auto j:m){
//         ll length = size[j.f];
//         ll index = length/i ;
//         index = index*i - 1;
//        if(index >= 0 && index < size[j.f]) sum += j.s[index];
//       }
//       ans.pb(sum);
//    }

// debug(m);
// debug(size);

   for(auto i:m){
    //    vl temp = i.s;
       ll x = size[i.f];
       vl temp(x,0);
       for(ll j = x; j > 0; j--){
          for(ll l = 1; l*l <= j; l++){
            if(j  % l == 0){
                // cerr << l << " " << j / l << endl;
                temp[l-1] = max(temp[l-1],i.s[j-1]);
                temp[(j/l) - 1] = max(temp[(j/l) - 1], i.s[j-1]);
            }
        }
        // debug(temp);
       }
       
       rep(j,x){
        ans[j] += temp[j];
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

