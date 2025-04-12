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
    int n,k; cin >> n >> k;
    if(n == 1){
        cout << k << endl;
        return;
    }
    int init = n;
    int count = 1;
    bool chk = true;
    multiset<int>ans;
    ans.insert(0);
    n--;
    int val = k;
    rep(i,val){

        if(n == 1 && k != 0){
            break;
        }
        if(n == 0) break;

        int limit = 32 - __builtin_clz(count);
        // cerr << count << " " << limit << endl;
        rep(j,limit){
            if(count & (1 << j)){
                if(val&(1 << j) ){}
                else{
                    chk = false;
                    break;
                }
                
            }
        }

        if(chk){
            ans.insert(count);
            n--;
            rep(j,32){
                if((k&(1 << j)) && (count & (1 << j))){
                   k -= (1 << j);
                }
            }
            count++;
            
        }
        else{
            break;
        }
        // cerr << count <<" " << k << endl;
    }

    int l = init - ans.size();
    if(l > 0) {ans.insert(k);
    l--;}
    while(l--){
        ans.insert(0);
    }
    
    for(auto i:ans){
        cout << i << " ";
    }
  cout << endl;
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




// if(k & (1 << i)){
//     if(i != 0) {ans.insert(1 << i); n--;}
//      k -= (1 << i);
     
//      if(n == 1 && k != 0){
//          ans.insert(k);
//          break;
//       }

//      bool chk = true;
//      if(chk && !ans.count(count)){
//          for(i = 0; i <= 32; i++){
//              if((val & (1 << i)) && (count & (1 << i))){
//              }
//              else{
//                 chk = false;
//                 break;
//              }
//         }
//      }
//      else if(ans.count(count)){
//          count++;
//      }
//      if(chk){
//          ans.insert(count);
//          count++;
//          n--;
//      }
//      else{
//          break;
//      }

   
//  }
//  debug(ans);
//  debug(k);