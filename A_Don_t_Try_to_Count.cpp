#include<iostream>
#include<string>
using namespace std;



int main(){
    int t; cin >> t;
    while(t--){
        int a,b; cin >>a >> b;
        string first , check;
        cin >> first >> check;
        int ans = 0;
        bool flag = false;
        
        if(first.find(check) != string::npos){    
                flag = true;
                cout << 0 << endl;
                continue;
            }


        for(int i = 0; i <= b/2; i++){
            first += first;
            if(first.find(check) != string::npos){
                ans++;
                flag = true;
                cout << ans << endl;
                break;
            }
            ans++;
        }
        if(!flag) cout << -1 << endl;

    }
    return 0;
}