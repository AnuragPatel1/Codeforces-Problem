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

struct Interactor{
    ll n;
    ll majorityElement = -1;
    vector<ll>arr;
    bool testing;
    int queriesSoFar;
    int limitQueries = 20;
    Interactor(ll n1,bool testing1){
        n = n1;
        queriesSoFar = 0;
        arr = {10,20,10,30,10,10,10};
        majorityElement = 10;
        testing = testing1;
        if(testing){
            cout << "Testing array: \n";
            for(auto i:arr)
                 cout << i << " ";
            cout << endl;    
        }
    }
    string queryInteractor(ll index){
        assert(queriesSoFar < limitQueries);
        queriesSoFar++; 
        if(arr[index-1] == majorityElement) return "Yes";
        else return "No";
    }
};

// bool testing = true; 

string query(ll index, Interactor &it){
    cout << "? "<< index << endl;
    string output;
    if(it.testing){
        output = it.queryInteractor(index);
        cout << "Iterator output: " << output << endl;
    }
    else{
        cin >> output;
    }
    return output;
}

void solve(){
    ll n; cin >> n;
     bool testing = false;
    Interactor it = Interactor(n,testing);
      
    int iterations = 20;
    ll ans = -1;
    for(int i = 0; i < iterations; i++){
        ll x = getRandomNumber(1,n);
        // getRandomNumber(L,R) gives a random number from L to R with
        // every number having equal number of probability of being choosen
        string result = query(x,it);
        if(result == "Yes"){
            ans=  x;
            break;
        } 
    }
    cout << "! " << ans << endl;

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

1