#include <stdio.h>
#include <math.h>

typedef long long ll;


int main() {
   int t; 
   scanf("%d",&t);
   while(t--){
    long long n;
    scanf("%lld", &n);

    long long low = 1;
    ll infi =2000000000000000000LL;
    long long ans = 0;

    while (low <= infi) {
        long long m = (low + infi) / 2;
        long long tmp = sqrt(m);

        if ((m - tmp) >= n) {
            ans = m;
            bool chk = true;
            infi = m - 1;
        } else {
            bool chk = false;
            low = m + 1;
        }
    }

    printf("%lld\n", ans);
   }
     return 0;
}