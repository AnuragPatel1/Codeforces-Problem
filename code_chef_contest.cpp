#include <bits/stdc++.h>
using namespace std;

#define int long long 

void solve(){
    int n; cin >> n;
    vector<int>arr1(n);
    for(int i = 0; i < n; i++) cin >> arr1[i];
    vector<int>arr2(n);
    for(int i = 0; i < n; i++) cin >> arr2[i];
    
    if(n == 1){
        cout << 1 << endl;
        return;
    }
    
    vector<pair<int,int>>arr(n);
    for(int i = 0; i < n; i++){
        arr[i] = make_pair(arr1[i],arr2[i]);
    }
    sort(arr.rbegin(),arr.rend());
    int ans = 0;
    
    int a = arr[0].first;
    int b = arr[0].second;
    
    for(int i =1; i < n; i++){
        if((arr[i].first*b) > (arr[i].second*a)){
            ans++;
        }
        else{
            a = arr[i].first;
            b = arr[i].second;
        }
    }

    // cout << ans <<" ";
     cout << n-ans << endl;
}

signed main() {
	int t; cin >> t;
	while(t--){
	    solve();
	}
	// return 0;
}
