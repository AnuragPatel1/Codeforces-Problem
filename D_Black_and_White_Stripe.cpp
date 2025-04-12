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
    string s; cin >> s;
    int l = 0;
    int r = k-1;
    int ans = k;
    int count = 0; 

    // if(k == 1){
    //     rep(i,n){
    //         if(s[i] == 'B'){out(0); return;}
    //     }
    //     out(1);
    //     return;
    // }

    rep(i,k){
     if(s[i] == 'W') count++;
    }
    ans = min(ans,count);
    
    int i = 0;
    int j = k-1;
    while(j < n-1){
        if(s[i] == 'B' && s[j+1] == 'W') count++;
        else if(s[i] == 'W' && s[j+1] == 'B') count--;
        ans = min(ans,count);
        i++;
        j++;
    }
    out(ans);
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

