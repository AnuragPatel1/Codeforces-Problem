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

void solve() {
    ll pairCount;
    cin >> pairCount;

    vpl originalPairs(pairCount);
    vl allElements(2 * pairCount);

    // Input original pairs and store individual values in allElements
    rep(i, pairCount) {
        cin >> originalPairs[i].f >> originalPairs[i].s;
        allElements[2 * i] = originalPairs[i].f;
        allElements[2 * i + 1] = originalPairs[i].s;
    }

    // Sort all elements for compression
    sort(all(allElements));

    // Create a map to store the compressed index of each unique value
    map<ll, ll> compressionMap;
    ll nextCompressedIndex = 1;
    for (const auto &element : allElements) {
        if (!compressionMap.count(element)) {
            compressionMap[element] = nextCompressedIndex++;
        }
    }

    // Compress the original pairs using the compressionMap
    vpl compressedPairs(pairCount);
    rep(i, pairCount) {
        compressedPairs[i].f = compressionMap[originalPairs[i].f];
        compressedPairs[i].s = compressionMap[originalPairs[i].s];
    }

    // Create a result vector with sum of compressed values and original pairs
    vector<tuple<ll, ll, ll>> sortedResults(pairCount);
    rep(i, pairCount) {
        ll compressedSum = compressedPairs[i].f + compressedPairs[i].s;
        sortedResults[i] = make_tuple(compressedSum, originalPairs[i].f, originalPairs[i].s);
    }

    // Sort the result by the sum of compressed values
    sort(all(sortedResults), [](const auto &a, const auto &b) {
        return get<0>(a) < get<0>(b);
    });

    // Output the original pairs in the order of their compressed sum
    for (const auto &result : sortedResults) {
        cout << get<1>(result) << " " << get<2>(result) << " ";
    }
    cout << endl;
}

int main() {
    int t; 
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
