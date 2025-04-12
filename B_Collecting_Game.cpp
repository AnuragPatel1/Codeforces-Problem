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
    vector<pair<int,int>>arr(n);
    int sum = 0;
    rep(i,n){
        int num; cin >> num;
        sum += num;
        arr[i] = make_pair(num,i);
    }
    sort(arr.rbegin(),arr.rend());
    mii m;
    // cout << m.size() <<" ";
    for(int i = 0; i < n; i++){
        pair<int,int>temp = arr[i];
        if(((i-1) >= 0) && sum >= arr[i-1].first){
            m[temp.second] = m[arr[i-1].second];
        }
        else{
            m[temp.second] = n-i-1;
        }
         sum -= temp.first;
    }
    for(auto i : m){
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

