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


int chk(string& s,int n,set<string>&st){
    
    if(n <= 0) return 0;
    
    int ans1 = 0;
    int ans2 = 0;
    
    // if i remove first element
    string temp = s.substr(1,n-1);
    // cout << temp <<" ";
    st.insert(temp);
    ans1 = 1 + chk(temp,n-1,st);

    // if i remove second element
    if(n >= 2 && s[0] != s[1]){
        string temp = s[0] + s.substr(2,n-2);
        // cout << temp <<" ";
        st.insert(temp);
        ans2 = 1 + chk(temp,n-1,st);
    }
    return ans1+ans2;
}



void solve(){
    int n; cin >> n;
    string s; cin >> s;
    set<string>st;
    int count = 0;
    int ans = chk(s,n,st);
    out(st.size());

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

