#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;


int main(){
    int t; cin >> t;
    while(t--){
        int n ; cin >> n;
        vector<int>arr;
        int check = INT_MAX;
        int count = 0;
        for(int i = 0; i < n; i++){
            int num ; cin >> num;
            if(check > num){
                check = num;
            }
            arr.push_back(num);
        }
        
        vector<int>b;
        vector<int>c;
        for(auto i : arr){
            if(i == check){
                b.push_back(i);
                count ++;
            }
            else c.push_back(i);
        }
        
        if(count == 0 || count == n){
            cout << -1 << endl;
            continue;
        }

        cout << count << " " << (n-count) << endl;
        for(auto i : b) cout << i <<" ";
        cout << endl;
        for(auto i : c) cout << i << " ";
        cout << endl;

    }
    return 0;
}