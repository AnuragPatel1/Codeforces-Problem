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
    int n,m; cin >> n >> m;
    vi arr(n); cin >> arr;
    vi rotate(m); cin >> rotate;
    int ind = 0;
    int maxi = INT_MAX;
    rep(i,m){
        if(maxi > rotate[i]){
            maxi = rotate[i];
            ind = i;
        }
    }
//    debug(ind);
    vi temp(m);
    int k= 0;
    for(int i = ind; i < m; i++){
        temp[k++] = rotate[i];
    }
    for(int i = 0; i < ind ;i++){
        temp[k++] = rotate[i];
    }
    
    rotate = temp;
    // debug(n-m);

    if(m == 1){
        rep(i,n){
            arr[i] = min(arr[i],rotate[0]);
        }
        cout << arr << endl;
        return;
    }

    int i = 0;
    while(i < (n-m)){
        if(arr[i] <= rotate[0]){
            i++; continue;
        }
        else{
            while(i < (n-m)){
                arr[i++] = rotate[0];
            }
             k = 0;
            while(k < m){
                arr[i++] = rotate[k++];
            }
            break;
        }
    }
 
     k = 0;
    for(int i = (n-m); i < n;i++){
        // cerr << arr[i] <<" " << rotate[k] << endl; 
        if(arr[i] < rotate[k]) { break;}
        else if(arr[i] == rotate[k]) {k++; continue;}
        else{
            while(i < n){
                // cerr << i <<" " << k << endl;
                arr[i] = rotate[k];
                i++,k++;
            }
            break;
        }
    }
cout << arr << endl;
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

