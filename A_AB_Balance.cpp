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
#define out(x) cout << x << endl;
#define YES cout<<"YES"<<endl;
#define NO cout<<"NO"<<endl;
#define pm cout<<"-1"<<endl;

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
#ifdef localenv
#define debug(x) _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.f); cerr << ","; _print(p.s); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

// Operator Overloads
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v){for (auto &it : v)cin >> it;return istream;}
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }

void solve(){
    YES;
}

int main()
{
    int t; 
    // t = 1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}








// ------------------------------------------------------------------------------------------//
#include<bits/stdc++.h>
using namespace std;
// Code Shortners
#define ub upper_bound
#define lb lower_bound
#define endl "\n"
#define ll long long
#define lli long long int
#define vi vector<int>
#define vc vector<char>
#define vs vector<string>
#define vll vector<ll>
#define vvi vector < vi >
#define vvc vector<vector<char>>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll,ll>>
#define pii pair<int,int>
#define mll map<ll,ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb push_back
#define ppb pop_back
#define pf  push_front
#define ppf pop_front
#define mp make_ pair
#define len(s) (int)s.size()
#define print(x) cout<<x<<endl;
#define REP(i,a,b) for( int i = a; i < b; i++)
#define REPE(i,a,b) for( int i = a; i <= b; i++)
#define all(a) (a).begin(), (a).end()
#define fast ios_bfse::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mod 1000000007
 
//---------------------------------------------------------------------------------------------------------------------
 
/*
//Hello!! Stalker---->STOP STALKING :)
 
  //Euclid's algorithm----O(logN)
  ll gcd(ll a, ll b) { if (b == 0) {return a;} return gcd(b, a % b);}
 
//Hello!! Stalker---->STOP STALKING :)
  //LCM
  ll lcm(ll a, ll b){return (a/gcd(a,b)*b);}
 
//Hello!! Stalker---->STOP STALKING :)
  //Prime factorisation----O(sqrt(n))
  vpll primefact(ll n, vll & cntt)  { vpll pfact; 
  for(ll i=2; i*i<=n; i++) if(n%i==0){ll cnt=0; while(n%i==0) {cnt++; n/=i;} cntt[i]+=cnt;}
  if(n>1) cntt[n]++;  return pfact; }
 
//Hello!! Stalker---->STOP STALKING :)
  //Binary Exponentiation(recursive)---divide & conquer-----> O(log b)
  ll powerRec(ll a, ll b) { 
  if(b==0) return 1;
  ll store = powerRec(a, b/2);
  if(b&1) {return (a* ((store*store) %mod)) %mod;} else{ return (store*store) %mod;} }
 
//Hello!! Stalker---->STOP STALKING :) 
  //Binary Exponentiation(iterative)---divide & conquer-----> O(log b)
  ll powerIter(ll a, ll b){
    ll ans=1;
    while(b){ if(b&1) { ans=(ans*a);} a=(a*a); b>>=1;} return ans;
  }
 
 //
ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}
 
ll mod_mul(ll a, ll b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}
 
ll mod_add(ll a, ll b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}
 
ll mod_sub(ll a, ll b) {a = a % mod; b = b % mod; return (((a - b) % mod) + mod) % mod;}
 
 //
//Hello!! Stalker---->STOP STALKING :)
  // Sieve of Erastosthenes---> O(n* log(logn))
   vector<ll> sieve(int n) {vll arr(n+1,0); vector<ll> vect; 
    arr[1]=1;
  for (int i = 2; i <= n; i++)
  if (arr[i] == 0) {arr[i]=i; 
  for (int j = 2 * i; j <= n; j += i)arr[j] = i;} return arr;}
 
//Hello!! Stalker---->STOP STALKING :)
  //sum_of_digits
  ll sum_of_digits(ll n) {ll sum=0; while(n>0) {sum+=n%10; n/=10; } return sum;}
 
//Hello!! Stalker---->STOP STALKING :)
  // Prime or not-----O(sqrt(n))
  bool isPrime(ll n)
  {if(n==1) return false; for(ll i=2; i<=sqrt(n); i++){ if(n%i==0) return false;} return true;}
 
//Hello!! Stalker---->STOP STALKING :)
  //Perfect square or not----->O(1)
  bool prfSq (ll n){ if(ceil(double(sqrt(n)) == floor(double(sqrt(n))))){ return 1; }else{ return 0;}}
 
//Hello!! Stalker---->STOP STALKING :)
//factorial of a no.----->O(n)
vll factt(ll n){
    vll fact(n+1,1);
    ll factorial=1;
    for(ll i=1; i<=n; i++){
      (fact[i]=(fact[i-1]*i))%=mod;
    }
    
    return fact;
  }
 
 
 
ll sqrtt(ll x){
  ll left = 0, right = 2000000123;
  while (right > left) {
    ll mid = (left + right) / 2;
    if (mid * mid > x) right = mid;
    else left = mid + 1;
  }
  return left - 1;
}
 
 
 
//Hello!! Stalker---->STOP STALKING :)
// regulr bracket string or not
bool regular(string a){
  ll cnt=0;
  for(ll i=0; i<a.length(); i++){
    if(a[i]=='(') cnt++;
    else cnt--;
    if(cnt<0) return false;
  }
  if(cnt>0) return false;
  return true;
}
 
//Hello!! Stalker---->STOP STALKING :)
//Reverse a number
vector<int> reverse_no(ll n){
    vi v;
    ll ans=0, rem;
    while(n != 0) {
    rem = n % 10;
    v.pb(rem);
    ans = ans * 10 + rem;
    n /= 10;
  }
  return v;
}
 
//**************************************************************************************************
 
//Hello!! Stalker---->STOP STALKING :)
ll countPrimes(ll n){
  if(n<2) return 0;
  int count=0;
  vector<bool> primes(n,1);
  primes[0] = false;
  primes[1] = false;
  for(ll i=2;i<n;i++){
    if(primes[i]){
      count++;
      for(ll j=i*i;j<n;j+=i) primes[j]=0;
    }
  }
  return count;
}
 
//Hello!! Stalker---->STOP STALKING :)
ll countDigit(ll n){
  ll count = 0;
  while (n != 0){
    n = n / 10;
    ++count;
  }
  return count;
}
 
//Hello!! Stalker---->STOP STALKING :)
// number is power of 2 or not
bool check(ll n){
  if(n==0) return false;
  return (ceil(log2(n)) == floor(log2(n)));
}
 
//---------------------------------------------------------------------------------------------------------------------
 
//pallendrome (two pointer)
bool ispalindrome(string s){
  ll i=0, j=s.length()-1;
  while(i<=j){
    if(s[i]!=s[j]) {return false;  break;}
    i++;
    j--;
  }
  return true;
}
 
 
//---------------------------------------------------------------------------------------------------------------------
 
//String Compare
bool comp(pair<int,string>&a, pair<int,string>&b){
  if(a.first<b.first) return true;
  else if(a.first==b.first) return a.second<=b.second;
  else return false;
}
 
//---------------------------------------------------------------------------------------------------------------------
 
//Is Vowel
 bool isvowel(char x){
  int p=int(x);
  if (x == 97 || x == 101 || x == 105 || x == 111 || x == 117 || x==65 || x==69 || x==73 || x==79 || x==85) return true;
  else return false;
}
 
//---------------------------------------------------------------------------------------------------------------------
 
//Dijkstra 
vll dijkstra(ll V, vpll A[], ll S){
  priority_queue<pii,vector<pii>,greater<pii>>pq;
  vll dist(V+1,1e9+7);
  dist[S]=0;
  pq.push({0,S});
  while(!pq.empty()){
    ll dis=pq.top().first;
    ll prev=pq.top().second;
    pq.pop();
    for(auto child:A[prev]){
      ll next=child.f;
      ll nextDist=child.s;
      if(dist[next]>dist[prev]+nextDist){
        dist[next]=dist[prev]+nextDist;
        pq.push({dist[next],next});
      }
    }
  }
  return dist;
}
 
//---------------------------------------------------------------------------------------------------------------------
 
 
//Shortest Distance
void shortest_distance(vector<vector<int>>&d){
  int n = d.size();
  for(int k=0;k<n;k++){
      for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
              if(d[i][k]==-1 || d[k][j]==-1)continue;
              if(d[i][j]==-1)   d[i][j] = d[i][k] + d[k][j];
              else d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
          }
      }
  }
}
 
 
//---------------------------------------------------------------------------------------------------------------------
 
 
vpll dir4={{1,0},{-1,0},{0,1},{0,-1}};
vpll dir8={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,-1}};
vpll knight_moves={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
 
 
//---------------------------------------------------------------------------------------------------------------------
 
//Vaild
bool valid(ll x, ll y, ll n, ll m){
  return x>=0 && x<n && y>=0 && y<m;
}
 
//---------------------------------------------------------------------------------------------------------------------
 
 
//DFS
void dfs(ll i, ll j, ll n, ll m, vvc &a, vvi &vis,ll &cnt){
  vis[i][j]=1;
  cnt++;
  for(auto x:dir4){
    ll p=i+x.f, q=j+x.s;
    if(valid(p,q,n,m) && !vis[p][q] && a[p][q]=='1') dfs(p,q,n,m,a,vis,cnt);
  }
}
 
 
//---------------------------------------------------------------------------------------------------------------------
 
 
// Returns nCr % p using Fermat's little theorem.
ll nCrModPFermat(ll n,ll r, ll p){
    // If n<r, then nCr should return 0
    if (n < r) return 0;
    // Base case
    if (r == 0) return 1;
    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    ll fac[n + 1];
    fac[0] = 1;
    REPE(i,1,n)
        // fac[i] = mod_mul(fac[i-1],i);
        return (fac[n] * modInverse(fac[r], p-2,p) % p * modInverse(fac[n - r], p-2,p) % p) % p;
}
*/
//---------------------------------------------------------------------------------------------------------------------


int main() {
    vector<vc> vec(21, vector<char>(21));
    REP(i,0,21) REP(j,0,21) cin >> vec[i][j];
    int maxi = 0;
    
    REPE(i,0,17){
        REPE(j,0,17) {
            int sum = 0;
            REP(r,i,i+4) REP(c,j,j+4) if (vec[r][c] == '1') sum++;
 
            maxi = max(maxi, sum);
        }
    }
    print(maxi);
 
    return 0;
}
