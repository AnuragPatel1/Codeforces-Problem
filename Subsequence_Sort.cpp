#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

#if defined(__GNUC__) || defined(__clang__)
#define BUILTIN_CLZLL __builtin_clzll
#else

#define BUILTIN_CLZLL(x) (63 - (long long)log2(x)) 
#endif

long long find_smallest_supermask(long long val, long long min_val) {
    if (val >= min_val) {
        return val;
    }
    long long result = 0;
    bool tight = true; 

    for (int j = 30; j >= 0; --j) {
        long long val_bit = (val >> j) & 1;
        long long min_val_bit = (min_val >> j) & 1;
        long long result_bit;

        if (tight) {

            result_bit = val_bit | min_val_bit;
            if (result_bit > min_val_bit) {
                tight = false;
            }
        } else { 
            result_bit = val_bit;
        }

        if (result_bit) {
            result |= (1LL << j);
        }
    }
    return result;
}

void solve() {
    int N;
    std::cin >> N;
    std::vector<int> A(N);
    bool sorted = true;
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
        if (i > 0 && A[i] < A[i - 1]) {
            sorted = false;
        }
    }

    if (sorted) {
        std::cout << 0 << std::endl;
        return;
    }

    long long required_mask = 0;
    long long last_val = 0;

    // O(N * log(max_A)) - This part is efficient.
    for (int i = 0; i < N; ++i) {
        long long current_val = A[i];
        long long candidate_val = find_smallest_supermask(current_val, last_val);
        required_mask |= (candidate_val & (~current_val));
        last_val = candidate_val;
    }
    
    // O(log(required_mask)) or O(1) with builtins - This part is now optimized.
    // The minimum k is 2^h, where h is the highest set bit of the required_mask.
    int highest_bit_pos = 63 - BUILTIN_CLZLL(required_mask);
    long long k = 1LL << highest_bit_pos;

    std::cout << k << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}