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
    map<int,int>m;
    
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0){
            int count = 0;
            while(n % i == 0){
                count++;
                n /= i;
            }
            m[i] = count;
        }
    }
    
    if(n > 0) m[n] = 1;

    // for(auto i : m){
    //     cout << i.first <<" " << i.second <<" ";
    // }


    int ans = 0;
    int lem = m.size();
    while(lem--){
        int value = INT_MAX;

        for(auto i : m){
            if(i.second < value && i.second != 0){
                value = i.second;
            }
        }
        
        // cout << value <<" ";

        int val = 1;
        for(auto &i:m){
            // val *= i.first;
            if(i.second) {i.second -= value; 
            val *= i.first;}
        }
        // cout << val <<" ";
       if(value != INT_MAX) ans += (val*value);
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
}

