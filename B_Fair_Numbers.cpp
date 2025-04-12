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
bool chk(int n){
    vi digits;
    int temp = n;
    while(temp > 0){
        if((temp % 10 != 0) && (temp%10 != 1))digits.push_back(temp%10);
        temp /= 10;
    } 
    int i = n;
        for(int j = 0; j < digits.size();j++){
            if(i % digits[j] != 0) return false;
        } 
    return true;
}


void solve(){
    int n; cin >> n;
    while(true){
        if(chk(n)){
            cout << n << endl;
            return;
        }
        n++;
    }
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

