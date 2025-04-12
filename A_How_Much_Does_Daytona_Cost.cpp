#include<iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        bool ans = false;
        for(int i = 0; i < n; i++){
            int num; cin >> num;
            if(num == k){
                ans = true;
            }
        }
        if(ans) cout <<"YES" << endl;
        else cout <<"NO" << endl;
    }
}
