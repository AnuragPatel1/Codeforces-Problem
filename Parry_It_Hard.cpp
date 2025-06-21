#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <climits> // For LLONG_MAX

using namespace std;

// Function to solve a single test case
void solve() {
    int n;
    long long x;
    cin >> n >> x;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<long long> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    // Step 1: Calculate M (maximum number of parries possible for the entire fight)
    int m_global = 0;
    long long current_x_for_m = x;
    priority_queue<long long> max_pq_for_m; // Max-heap to store B values of parried attacks

    for (int i = 0; i < n; ++i) {
        if (current_x_for_m >= b[i]) {
            max_pq_for_m.push(b[i]);
            current_x_for_m--;
            m_global++;
        }
        // If current_x_for_m drops below a[i], we must undo parries.
        while (current_x_for_m < a[i] && !max_pq_for_m.empty()) {
            current_x_for_m++;
            m_global--;
            max_pq_for_m.pop();
        }
        // If even after undoing parries, X is too low, then it's impossible to win.
        if (current_x_for_m < a[i]) { 
            m_global = -1; // Indicate impossible
            break;
        }
    }

    string result_str(n, '0');

    if (m_global == -1) {
        // If it's impossible to win the fight at all, then no maximal sequence exists.
        cout << result_str << endl;
        return;
    }
    
    // Step 2: Precompute prefix DP states
    // prefix_parry_count[i]: max parries from 0 to i (inclusive)
    // prefix_min_X_rem[i]: min X remaining after these parries
    vector<int> prefix_parry_count(n);
    vector<long long> prefix_min_X_rem(n);

    long long current_x_prefix = x;
    int current_parries_prefix = 0;
    priority_queue<long long> max_pq_prefix;

    for (int i = 0; i < n; ++i) {
        if (current_x_prefix >= b[i]) {
            max_pq_prefix.push(b[i]);
            current_x_prefix--;
            current_parries_prefix++;
        }
        while (current_x_prefix < a[i] && !max_pq_prefix.empty()) {
            current_x_prefix++;
            current_parries_prefix--;
            max_pq_prefix.pop();
        }
        if (current_x_prefix < a[i]) { 
            prefix_parry_count[i] = -1; // Indicate impossible prefix
            prefix_min_X_rem[i] = -1;
            // Propagate failure for subsequent prefix calculations
            for (int j = i + 1; j < n; ++j) {
                prefix_parry_count[j] = -1;
                prefix_min_X_rem[j] = -1;
            }
            break;
        }
        prefix_parry_count[i] = current_parries_prefix;
        prefix_min_X_rem[i] = current_x_prefix;
    }

    // Step 3: Precompute suffix DP states (reversed logic for X_needed)
    // suffix_parry_count[i]: max parries from i to N-1
    // suffix_min_X_needed[i]: min X required *at the start of i* to achieve these parries AND win.
    vector<int> suffix_parry_count(n + 1);
    vector<long long> suffix_min_X_needed(n + 1);

    suffix_parry_count[n] = 0;
    suffix_min_X_needed[n] = 0; // If no attacks left, 0 parries, 0 X needed.

    long long current_x_needed_suffix_sim = 0; // Represents max(A_j) for dodged + num_parries (effectively X consumption)
    int current_parries_suffix_sim = 0;
    priority_queue<long long> max_pq_suffix_sim; // Max-heap, stores B values of parried attacks in this suffix

    for (int i = n - 1; i >= 0; --i) {
        // When processing i, we need to ensure current_x_needed_suffix_sim can handle A[i]
        current_x_needed_suffix_sim = max(current_x_needed_suffix_sim, a[i]);
        
        // Option to parry attack i:
        // If X_needed is sufficient for B[i] and we can afford to use 1 more X point.
        if (current_x_needed_suffix_sim + 1 >= b[i]) {
            max_pq_suffix_sim.push(b[i]);
            current_x_needed_suffix_sim++; // One more X point is consumed/needed at the start
            current_parries_suffix_sim++;
        }

        // Adjustment for X exceeding initial X
        // If the 'cost' of current suffix (max(A_j) + parries) exceeds total X, we must undo.
        while (current_x_needed_suffix_sim > x && !max_pq_suffix_sim.empty()) {
            current_x_needed_suffix_sim--;
            current_parries_suffix_sim--;
            max_pq_suffix_sim.pop();
        }

        // If even after adjustments, X is globally impossible
        if (current_x_needed_suffix_sim > x) { // This state is unreachable with initial X
            suffix_parry_count[i] = -1;
            suffix_min_X_needed[i] = -1; // Represents impossible
        } else {
            suffix_parry_count[i] = current_parries_suffix_sim;
            suffix_min_X_needed[i] = current_x_needed_suffix_sim;
        }
    }

    // Step 4: Check for each 'i' if it can be part of an M_global sequence
    for (int i = 0; i < n; ++i) {
        bool possible = false;

        // Get prefix state up to i-1
        int parries_from_prefix = (i == 0) ? 0 : prefix_parry_count[i-1];
        long long x_rem_from_prefix = (i == 0) ? x : prefix_min_X_rem[i-1];

        // Check if prefix was successful
        if (parries_from_prefix == -1) { 
            possible = false;
        } 
        // Check if we can parry attack `i` with remaining X from prefix
        else if (x_rem_from_prefix < b[i]) { 
            possible = false;
        } 
        else { // Prefix is good, and we can parry 'i'
            long long x_after_parry_i = x_rem_from_prefix - 1; // X after parrying 'i'
            int total_parries_including_i = parries_from_prefix + 1; // Parries from prefix + parry 'i'

            // Get suffix state from i+1
            int parries_from_suffix = (i == n - 1) ? 0 : suffix_parry_count[i+1];
            long long x_needed_for_suffix = (i == n - 1) ? 0 : suffix_min_X_needed[i+1];

            // Check if suffix is successful
            if (parries_from_suffix == -1) {
                possible = false;
            } 
            // Check if X after parrying 'i' is sufficient for the suffix requirements
            else if (x_after_parry_i < x_needed_for_suffix) {
                possible = false;
            } 
            // Check if total parries achieved matches M_global
            else if (total_parries_including_i + parries_from_suffix == m_global) {
                possible = true;
            } 
            else {
                possible = false;
            }
        }
        if (possible) {
            result_str[i] = '1';
        }
    }

    cout << result_str << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}