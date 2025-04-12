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

bool compare(pair<int,int>&a,pair<int,int>&b){
    if(a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}

void solve(){
    int n ; cin >> n;
    int k; cin >> k;
    vector<pair<int,int>>arr;
    vi a(n);
    rep(i,n){
        int num; cin >> num;
        a[i] = num;
        if(num % k == 0){
          cout << i+1 << " ";
        }
       else  arr.push_back(make_pair(num%k,i+1));
    }
    sort(arr.begin(),arr.end(),compare);

    // for(auto i : arr) cout << i.first <<"=" << i.second <<" ";

    for(auto i :arr){
        cout << i.second << " ";
    }
    cout << endl;
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

