#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t; cin >> t;
	while(t--){
	    int n; cin >> n;
        string s = to_string(n);
        if(s.substr(0,2) != "10"){
            cout << "NO" << endl;
            continue;
        }
	    else{
            
            string l = s.substr(2,s.length()-2);
            if(l[0] == '0'){
                cout <<"NO" << endl;
            }
            else{
                cout << "YES" << endl;
            }
        }
	    
	}


    return 0;
}
