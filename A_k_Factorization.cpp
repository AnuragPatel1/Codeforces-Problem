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
#define out(x) cout << x << endl
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
    vi ans;
    int i = 2;
    // while(k--){ 
        while(i <= n){
            if(k == 1) break;
            if(n % i == 0){
                n = n/i;
                k--;
                ans.push_back(i);
                
            }
            else i++;
        }
        if(((n < i) && k > 1) || n == 1){
            cout << -1 << endl;
            return;
        }
    rep(j,ans.size()) cout << ans[j] <<" ";
    cout << n << endl;
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

