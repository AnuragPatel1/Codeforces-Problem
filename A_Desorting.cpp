#include<iostream>
#include<limits.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n ; cin >> n;
        int num ; cin >> num;
        int prev = num;
        int diff = INT_MAX;
        bool flag = false;
        for(int i = 0; i < n-1; i++){
            cin >> num;
            if(num < prev || flag){
                flag = true ;
            }
            else{
                if(diff > (num - prev)){
                    diff = num - prev;
                }
                prev = num;
            }
        }
        if(flag) cout << 0 << endl;
        else cout << (diff/2) + 1 << endl;
    }
    return 0;
}