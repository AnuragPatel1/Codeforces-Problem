// Author: Utkarsh Chaudhary
/* Utkarsh Chaudhary--> Codeforces @utkarsh_c30 */
#include "bits/stdc++.h"
using namespace std;
const int mod = 1e9 + 7;
typedef long long ll;
#define all(a) (a).begin(), (a).end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define f(i, n) for (ll i = 0; i < (n); i++)
#define input for(ll i=0;i<n;i++){cin>>arr[i];}
#define rev(i, n) for (ll i = (n) - 1; i >= 0; i--)
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vpi vector<pi>
#define vpl vector<pl>
#define nl '\n'
#define umap unordered_map<ll, ll>
#define c(x) cout << (x) << nl
#define in(vec, n) { \
    for (int i = 0; i < (n); ++i) { \
        cin >> (vec)[i]; \
    } \
}

void uc(){
    ll n;
    cin>>n;
    if(n%25==0)cout<<0<<endl;
    else {
        vector<long long>temp;
        ll r;
        while(n>0){
          r=n%10;
          temp.push_back(r);
          n/=10;
        }
        reverse(temp.begin(),temp.end());
        ll m=temp.size()-1;
        bool f=false;
        bool z=false;
        ll end;
        ll start;
        for(int i=m;i>=0;i--){
            if(temp[i]==5 && f==false) {
                end=i;
                f=true;
                continue;
            } 
            else if(temp[i]==0 && z==false){
                end=i;
                z=true;
                continue;
            }
            if(f){
                if(temp[i]==2 || temp[i]==7){
                    start=i;
                    break;
                }
            }
             if(z){
                if(temp[i]==0 || temp[i]==5){
                    start=i;
                    break;
                }
            }
        }
           ll sum=(temp.size()-1)-end;
           sum+=end-start-1;
        
           cout<<sum<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--)
    {
        uc();
    }
    return 0;
}