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
    int n; 
    cin >> n;
    mii m;
    vi arr(n);
    rep(i,n){
        int num; cin >> num;
        arr[i] = num;
        m[num]++;
    }
    if(m.size() == n){
        print(-1);
        return;
    }
    int k = 0;
    vi ans;
    for(auto &i:m){
        if(i.second >= 4){
            k+=2;
            int d = 4;
            while(ans.size() < 4){
                ans.pb(i.first);
            }
            print(ans);
            return;
        }
        else if(i.second >= 2){
            k++;
            m[i.f] -= 2;
            int d = 2;
            while(d--){
                ans.pb(i.first);
            }
            if(k == 2){
               print(ans);
               return;
            }
        }
    }
   
//    debug(ans);
   
//    arr.erase(ans[0].find(all(arr)),1);
// arr.erase(std::remove(arr.begin(), arr.end(), ans[0]), arr.end());
// arr.erase(std::remove(arr.begin(), arr.end(), ans[0]), arr.end());




   sort(all(arr));
// debug(arr);
   
//    int x = lower_bound(all(arr),ans[0]) - arr.begin();
   for(int i = 0; i < n; i++){
    if(arr[i] == ans[0]){
        arr[i] = -1;
        arr[i+1] = -1;
        break;
    }
   }
    sort(all(arr));
   int i = 2,j = n-1;
   
//    debug(arr);
//    debug(m);
//   k = ans[0]*2 + arr[i];
//    int l = lower_bound(all(arr),k) - arr.begin();
//    debug(l);


   while(i < n){
        int k = ans[0]*2 + arr[i];
        int l = lower_bound(all(arr),k) - arr.begin();
        l--;
        if(l > i){
            for(int k = l; k > i; k--){
                if(m[arr[k]] != 0){
                    ans.pb(arr[i]);
                    ans.pb(arr[k]);
                    print(ans);
                    return;
                }
            }
        
        
      }
      i++;
   }
  print(-1);
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

