#include <iostream>
#include <cmath>
using namespace std;

long long calcX(long long n, long long k, long long i) {
    long long sum1 = (i * (2 * k + i - 1)) / 2;
    long long totalSum = (n * (2 * k + n - 1)) / 2;
    // cout << totalSum <<" ";
    long long sum2 = totalSum - sum1;
    return abs(sum1 - sum2);
}

long long findMinX(long long n, long long k) {
    long long left = 1, right = n;
    while (left < right) {
        long long mid = left + (right - left) / 2;
        long long x1 = calcX(n, k, mid);
        long long x2 = calcX(n, k, mid + 1);
        cout<< mid <<" " << x1 <<" " << x2 <<" ";
        if (x1 <= x2) {
            right = mid; 
        } else {
            left = mid + 1;
        }
    }
    return calcX(n, k, left);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        cout << findMinX(n, k) << endl;
    }
    return 0;
}
