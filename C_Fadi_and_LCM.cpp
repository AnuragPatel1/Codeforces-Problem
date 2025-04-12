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

bool chk(int a,int b){
    int t = min(a,b);
    int r = max(a,b);
    for(int i = 2; i*i <= t; i++){
        if((a % i == 0) && (b % i == 0)) return false;
    }
    
    if(r % t == 0) return false;

    return true;
}

void solve(){
    int n; cin >> n;
    int ans = 1;
    for(int i = 2; i*i <= n;i++){
        if(n % i == 0 && chk(i,n/i)) ans = i;
    }
   int ans2 = n/ans;
   if(ans == ans2){
    cout << 1 << " " << n << endl;
   }
   else cout << ans << " " << ans2 << endl;

}

signed main()
{
    int t; 
    t = 1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
}

