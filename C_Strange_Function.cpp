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
    int n,i,j = 0, a,b;
    cin >> n;
    ll ans = 0,k = 2,c= 2, num = 0,already = 0;

    while(n > 0){
        ll div = n/c;
        num = num + (n-div)-already;
        ans = (ans+((((n-div-already)%M) % M)*k)%M)%M;
        already = num;
        if(num == n) break;
        ll g = __gcd(c,k+1);
        ll d = (k+1)/g;
        k++;
        while(d== 1){
            k++;
            d = k/__gcd(k,c);
        }
        c = c*d;
    }
    cout << ans << endl;
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

