#include <bits/stdc++.h>

using namespace std;

#define int long long int
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

// // Debug Overloads
// #ifdef localenv
// #define debug(x) _print(x); cerr << endl;
// #else
// #define debug(x)
// #endif

// void _print(ll t) {cerr << t;}
// void _print(int t) {cerr << t;}
// void _print(string t) {cerr << t;}
// void _print(char t) {cerr << t;}
// void _print(double t) {cerr << t;}

// template <class T, class V> void _print(pair <T, V> p);
// template <class T> void _print(vector <T> v);
// template <class T> void _print(set <T> v);
// template <class T> void _print(multiset <T> v);
// template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.f); cerr << ","; _print(p.s); cerr << "}";}
// template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

// // Operator Overloads
// template<typename T> // cin >> vector<T>
// istream& operator>>(istream &istream, vector<T> &v){for (auto &it : v)cin >> it;return istream;}
// template<typename T> // cout << vector<T>
// ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }

void merge(int s,int e,vector<int>&arr, int&ans){
    // cerr << s <<" " << e << endl;
    int start = s;
    int end = e;
    int mid = start + (end-start)/2;
    vi arr1;
    vi arr2;
    for(int i = start; i <= mid; i++){
        arr1.pb(arr[i]);
    }
    for(int i = mid+1; i <= end; i++){
        arr2.pb(arr[i]);
    }
    int i = 0;
    int j = 0;
    int k = s;
    int l1 = arr1.size();
    int l2 = arr2.size();
    while(i < l1 && j < l2){
        if(arr1[i] > arr2[j]){
            arr[k] = arr2[j];
            ans += (l1-i);
            j++;
            k++;
        }
        else if(arr1[i] <= arr2[j]){
            arr[k] = arr1[i];
            i++;
            k++;
        }
    }
    while(i < l1){
       arr[k] = arr1[i];
       i++;k++;   
    }
    while(j < l2){
        arr[k] = arr2[j];
        k++,j++;
    }
    

}

void mergesort(int s,int e, vector<int>&arr, int& ans){
    // cerr << s <<" " << e << endl;
    if(s >= e) return;
    int mid = s+(e-s)/2;
    // debug(mid);
    mergesort(s,mid,arr,ans);
    mergesort(mid+1,e,arr,ans);
    
    merge(s,e,arr,ans);
}

int solveans(vi &arr,int &n){
    // int n; cin >> n;
    // vi arr(n);rep(i,n)cin>>arr[i];
    int ans = 0;
    int s = 0;
    int e = n-1;
    mergesort(s,e,arr,ans);
    return ans;
}

void solve(){
  int n; cin >> n;
  vi a(n+1),b(n+1);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];

  mii idx;
  rep(i,n+1)idx[b[i]] = i;

  vi arr(n+1);
  rep(i,n+1)arr[i] = idx[a[i]]; 


  ll ans = solveans(arr,n);
  print(ans);
}

signed main()
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

