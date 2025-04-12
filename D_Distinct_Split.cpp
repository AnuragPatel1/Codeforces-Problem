#include <bits/stdc++.h>

using namespace std;

#define PI (3.141592653589)
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

// int ans(int i,int e,string s,unordered_map<char,int>m){
//     int score = 0;
//     unordered_map<int,int>m1;
//     while(i < e){
//         if(m1.find(s[i]) != m1.end()) m1[s[i]]++;
//         else m1[s[i]] = 1;
//         i++;
//     }
//     score = m1.size();

//     for(auto k : m){
//         if(m[k.first] - m1[k.first] > 0) score++;
//     }
//   return score;
// }

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int cal = 0;
    int maxAnswer = 0;
    int j = 0;
     map<char,int>m;
     while(j < n){
        if(m.find(s[j]) != m.end())m[s[j]]++;
        else m[s[j]] = 1;
        j++;
     }
     
     maxAnswer = 2*m.size();
     int score = m.size();

     map<int,int>m1;
     int key = 0;

    for(int i = 0; i < n; i++){
        // // string t1 = s.substr(0,i);
        // // string t2 = s.substr(i,s.length()-i);
        // cal = max(cal,ans(0,i,s,m));
        // if(cal == maxAnswer) break;
        
        if(m1.find(s[i]) != m1.end()){
            m1[s[i]]++;
            m[s[i]]-- ;
            if(m[s[i]] == 0) key++; 
        }
        else {
            m1[s[i]] = 1;
            m[s[i]]-- ;
            if(m[s[i]] == 0) key++; 
        }
        int ke = m1.size() + m.size();
        // cout << ke <<" ";
        cal = max(cal,ke-key);
        if(cal == maxAnswer) break;
    }
    out(cal);
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

