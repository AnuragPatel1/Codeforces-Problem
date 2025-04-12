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
    int n; cin >> n;
    char a; cin >>a ;
    string s; cin >> s;
    int i = 0; int j = 0;
    int first = -1;
    int ans = INT_MIN;
    while(i < n){
        // cout << "Hi" <<" ";
        
        if(first == -1 && s[i] == 'g') first = i;
        
        // if(first == -1){
        //     while(s[i] != a) i++;
        //     j = i;
        //     while(s[i] != 'g') i++;
        //     ans = i-j;
        //     first = i;
        //     // cout << ans <<" ";
        // }
         if(s[i] == a){
            j = i;
            while((i < n) && (s[i] != 'g')){
                // if(first == -1 && s[i] == 'g') first = i;
                i++;
                if(i == n){
                    // first--;
                    // cout << first <<" ";
                    ans = max(ans,i-j+first);
                    break;
                }
            } 
            if(first == -1 && s[i] == 'g') first = i;
            ans = max(ans,i-j);
        }
         i++;
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

