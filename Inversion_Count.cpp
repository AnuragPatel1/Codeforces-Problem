#include <bits/stdc++.h>

using namespace std;
#define int long long int
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


void merge(int s,int e,vector<int>&arr, int&ans){
    // cerr << s <<" " << e << endl;
    int start = s;
    int end = e;
    int mid = start + (end-start)/2;
    vi arr1;
    vi arr2;
    for(int i = start; i <= mid; i++){
        arr1.pb(arr[i]);
    }
    for(int i = mid+1; i <= end; i++){
        arr2.pb(arr[i]);
    }
    int i = 0;
    int j = 0;
    int k = s;
    int l1 = arr1.size();
    int l2 = arr2.size();
    while(i < l1 && j < l2){
        if(arr1[i] > arr2[j]){
            arr[k] = arr2[j];
            ans += (l1-i);
            j++;
            k++;
        }
        else if(arr1[i] <= arr2[j]){
            arr[k] = arr1[i];
            i++;
            k++;
        }
    }
    while(i < l1){
       arr[k] = arr1[i];
       i++;k++;   
    }
    while(j < l2){
        arr[k] = arr2[j];
        k++,j++;
    }
    

}

void mergesort(int s,int e, vector<int>&arr, int& ans){
    // cerr << s <<" " << e << endl;
    if(s >= e) return;
    int mid = s+(e-s)/2;
    // debug(mid);
    mergesort(s,mid,arr,ans);
    mergesort(mid+1,e,arr,ans);
    
    merge(s,e,arr,ans);
}

void solve(){
    int n; cin >> n;
    vi arr(n);rep(i,n)cin>>arr[i];
    int ans = 0;
    int s = 0;
    int e = n-1;
    mergesort(s,e,arr,ans);
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
    return 0;
}

