#include<iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,total = 0;
        cin >> n;
        
        for(int i = 0; i < n-1; i++){
            int num = 0; cin >> num;
            // cout << num <<" ";
            total += num;
        }
        // cout << total <<" ";
        cout <<(-1 * total) << endl;
    }
    return 0;
}
