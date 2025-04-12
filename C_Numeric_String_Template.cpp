#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t; cin >> t;
	while(t--){
	    int n; cin >> n;
        bool ans = true;
        unordered_map <int, vector<int> >arr;
        for(int i = 0; i < n; i++){
            int num; cin >> num;
                arr[num].push_back(i);
            
        }

        
        int number ; cin >>number;
        for(int i = 0; i < number; i++){
            string temp; cin >> temp;
            if(temp.size() != n){
                ans = false; 
            }
            else{
                for(auto a : arr){
                    if(a.second.size() == 1){
                        continue;
                    }
                    for(int b = 0; b < a.second.size()-1; b++){
                        if(temp[a.second[b]] != temp[a.second[b+1]] ){
                            ans = false;
                        }
                    }
                }
            }

            if(ans) cout << "YES" << endl;
            else cout <<"NO" << endl;
        }
	    
	    
	    
	}


    return 0;
}
