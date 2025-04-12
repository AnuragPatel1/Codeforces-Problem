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

int power(int a,int b){
    int temp = 1;
    while(b){
        if(1&b) temp = (temp*a)%M;
        a = (a*a)%M;
        b = b/2;
    }
    return temp;
}

void solve(){
    int n; cin >> n;
    map<int,int>m;
    int number = 1;
    while(n--){
        int a,b; cin >> a >> b;
        m[a] = b;
        number *= (b+1); 
    }
    
    int add = 1;
    int c = 0;
    for(auto i:m){
        int key = i.first;
        int value = i.second;
        c += i.second;
        int sum = 0;
        while(value != -1){
           sum = (sum + power(key,value))%M;
           value--;
        }
        add = (add*sum)%M;
    }

    int multiply = 1;
    int key = number/2;
    // cout << key << endl;
    for(auto i : m){
        multiply = (multiply*power(i.first,i.second*key))%M;
        // cout << multiply << endl;
    }
    cout << number%M <<" " << add << " " << multiply << endl;

}

signed main()
{
    int t; 
    t = 1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
}

