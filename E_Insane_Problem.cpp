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

// Debug Overloadsstream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }

ll power(int a,int x){
    ll temp = 1;
    while(x > 0){
        
        if(x&1) temp = a*temp;

        x = x >> 1;
        a *=a; 
    }
    return temp;
}

void solve(){
    ll k,a,b,x,y; cin >> k >> a >> b >> x>>y;
    ll ans = 0;
    ans = min(b,y) - max(a,x)+1;
    if(ans < 0) ans = 0;
    // cout << ans <<" ";
    ll t = 1;

    // debug(power(k,t));
    while(power(k,t) <= y){
        // debug(power(k,t));
        cout << power(k,t) << " ";
        ll i =0;
        for(i = a; i <= b; i++){
            if(i*power(k,t) >= x && i*power(k,t) <= y) break;
        }
        ll j = 0;
        for(j = b; j >= a; j--){
            if(j*power(k,t) >= x && j*power(k,t) <= y) break;
        }
        if(j-i + 1 > 0)
        ans += (j-i)+1;
        // cout << ans <<" ";
        t++;
    }
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

