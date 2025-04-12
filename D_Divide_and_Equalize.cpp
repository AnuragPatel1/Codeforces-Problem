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
    int n; cin >> n;
    int len = n;
    map<int,int>m;
    while(n--){
        int k; cin >> k;
        
        for(int i = 2; i *i <= k; i++){
            if(k % i == 0){
                int count = 0;
                while(k % i == 0){
                    count++;
                    k /= i;
                }
                if(m.find(i) != m.end()) m[i] += count;
                else m[i] = count;
            }
        }
        
        if(k > 1){
            if(m.find(k) != m.end()) m[k] += 1;
                else m[k] = 1;
        }
    }
    
    // for(auto i:m){
    //     cout << i.first <<" " << i.second <<" ";
    // }

    for(auto i : m){
        if(i.second % len){
            NO; return;
        }
    }
   YES;
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

