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
    int a,b; cin >> a >> b;
    vi arr1;
    
    int c = a,d = b;
    bool chk = true;
    bool flag = true;
    while(a > 0 && b > 0){
        // if(a == 1){
        //     arr1.pb(1),a--;
        // }
        // else if(b == 1){
        //     arr1.pb(2),b--;
        // }
        // else{
            // arr1.pb(1),a--;
            // arr1.pb(2),b--;
        // }

        if(chk){
            arr1.pb(1),a--;
            arr1.pb(2),b--;
            chk = false;
        }
        else{
            if(flag){
                int k = arr1.back();
                if(k ==1)a--;
                else b--;
                arr1.pb(k);
                flag = false;
            }
            else{
                int k = arr1.back();
                k = (k==1) ? 2 : 1;
                if(k==1)a--;
                else b--;
                arr1.pb(k);
                flag = true;
            }
        }


    }
    while(b--)arr1.pb(2);
    while(a--)arr1.pb(1);

    a = c,b=d;
    vi arr2;
    chk = true;
    flag = true;
    while(a > 0 && b > 0){
        // if(a == 1){
        //     arr2.pb(1),a--;
        // }
        // else if(b == 1){
        //     arr2.pb(2),b--;
        // }
        // else{
        //     arr2.pb(2),b--;
        //     arr2.pb(1),a--;
        // }

        
        if(chk){
            arr2.pb(2),b--;
            arr2.pb(1),a--;
            chk = false;
        }
        else{
            if(flag){
                int k = arr2.back();
                if(k ==1)a--;
                else b--;
                arr2.pb(k);
                flag = false;
            }
            else{
                int k = arr2.back();
                k = (k==1) ? 2 : 1;
                if(k==1)a--;
                else b--;
                arr2.pb(k);
                flag = true;
            }
        }

    }
    while(b--)arr2.pb(2);
    while(a--)arr2.pb(1);

    // debug(arr1);
    // debug(arr2);

    int ans1 = 0;
    rep(i,(c+d-1)){
        if(arr1[i] == arr1[i+1]) ans1++;
    }
    int ans2 = 0;
    rep(i,(c+d-1)){
        if(arr2[i] == arr2[i+1]) ans2++;
    }
    
    // debug(arr2);

    int ans = max(ans1,ans2);
    ans1 = c+d-1-ans;

    cout << ans <<" " << ans1 << endl;


}

int main()
{
    int t; 
    t = 1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

