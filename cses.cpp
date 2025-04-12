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


void solve(){
    int n; cin >> n;
    if(n == 1){
        cout << 1 << endl;
        return;
    }
    map<int,int>m;
    while(n != 1){
        int temp = n;
        for(int i = 2;i*i <= temp; i++){
            if(temp % i == 0){
                int count = 0;
                while(temp % i == 0){
                    count++;
                    temp = temp/i;
                }
                if(m.find(i) != m.end()) m[i]+=count;
                else m[i] = count;
            }
        }
        if(temp > 1){
            if(m.find(temp) != m.end()) m[temp]+=1;
                else m[temp] = 1;
        }
        //  for(auto i:m) cout << i.first << " " << i.second <<endl;
        n--;
    }
    
    // for(auto i:m) cout << i.first << " " << i.second <<" ";

    int ans = 1;
    for(auto i:m){
        ans = (ans*(i.second+1))%M;
    }
print(ans);
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

