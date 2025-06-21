#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

// Using std namespace for brevity in competitive programming contexts
using namespace std;

// Function to solve a single test case
void solve() {
    int n;
    int q; // Q is always 0 in this easy version
    cin >> n >> q;
    string s1, s2;
    cin >> s1 >> s2;

    // Store the 1-based positions of all '1's in each row
    vector<long long> ones_pos_row1;
    vector<long long> ones_pos_row2;
    for (int i = 0; i < n; ++i) {
        if (s1[i] == '1') {
            ones_pos_row1.push_back(i + 1);
        }
        if (s2[i] == '1') {
            ones_pos_row2.push_back(i + 1);
        }
    }

    int count1 = ones_pos_row1.size();
    int count2 = ones_pos_row2.size();

    // Precompute prefix sums of positions for row 1's '1's
    // This helps calculate the cost to move the leftmost '1's
    vector<long long> prefix_sum_pos1(count1 + 1, 0);
    for (int i = 0; i < count1; ++i) {
        prefix_sum_pos1[i + 1] = prefix_sum_pos1[i] + ones_pos_row1[i];
    }

    // Precompute suffix sums of positions for row 2's '1's
    // This helps calculate the cost to move the rightmost '1's
    vector<long long> suffix_sum_pos2(count2 + 1, 0);
    for (int i = count2 - 1; i >= 0; --i) {
        suffix_sum_pos2[i] = suffix_sum_pos2[i + 1] + ones_pos_row2[i];
    }

    long long min_total_ops = -1;

    // Iterate through all possible columns 'k' for the down-move
    for (int k = 1; k <= n; ++k) {
        // Number of '1's needed in the prefix of row 1
        long long ones_needed1 = k;
        // Number of '1's needed in the suffix of row 2
        long long ones_needed2 = n - k + 1;

        // Check if this path is feasible (i.e., enough '1's are available in each row)
        if (count1 < ones_needed1 || count2 < ones_needed2) {
            continue;
        }

        // --- Calculate cost for row 1 ---
        // We need to move the 'ones_needed1' leftmost '1's to positions 1, 2, ..., ones_needed1
        long long sum_initial_pos1 = prefix_sum_pos1[ones_needed1];
        long long sum_target_pos1 = ones_needed1 * (ones_needed1 + 1) / 2;
        long long cost1 = sum_initial_pos1 - sum_target_pos1;

        // --- Calculate cost for row 2 ---
        // We need to move the 'ones_needed2' rightmost '1's to positions k, k+1, ..., n
        long long sum_initial_pos2 = suffix_sum_pos2[count2 - ones_needed2];
        long long sum_target_end = (long long)n * (n + 1) / 2;
        long long sum_target_start_prefix = (long long)(k - 1) * k / 2;
        long long sum_target_pos2 = sum_target_end - sum_target_start_prefix;
        long long cost2 = sum_target_pos2 - sum_initial_pos2;
        
        long long current_total_ops = cost1 + cost2;
        
        // Update the minimum operations found so far
        if (min_total_ops == -1 || current_total_ops < min_total_ops) {
            min_total_ops = current_total_ops;
        }
    }

    cout << min_total_ops << endl;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}