#include <bits/stdc++.h>

using namespace std;

#define PI (3.141592653589)
#define int long long int
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
void solve(){
    int n,k; cin >> n >> k;
    vi arr(n);
    int xxor = 0;
    int gcd;
    bool chk =true;
    rep(i,n){
        int num; cin >> num;
        arr[i] = num;
        if(num != k) chk = false;
        if(i == 0) gcd = num;
        else gcd = __gcd(num,gcd);
        xxor ^= num;
    }
    
    if(chk){
        print(0);
        return;
    }

    if(gcd % k == 0){
        cout << 1 << endl; return;
    }
    if(xxor == 0 || xxor == k){
        cout << 1 << endl; return;
    }
    else{
        if(!(n&1)){
            cout << 2 << endl; return;
        }
        else print(3);
    }

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
}

