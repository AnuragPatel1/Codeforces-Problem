#include <iostream>
#include <vector>
using namespace std;

// Function to count the number of valid triplets
vector<long long> countTriplets(int T, vector<pair<int, vector<int>>>& testCases) {
    vector<long long> results;

    // Iterate over each test case
    for (auto& testCase : testCases) {
        int N = testCase.first;
        vector<int>& A = testCase.second;

        // Frequency array to count occurrences of numbers between 1 and 100
        vector<int> freq(101, 0);
        for (int i = 0; i < N; ++i) {
            freq[A[i]]++;
        }

        long long count = 0;

        // Iterate over all possible pairs of values x, y where 1 ≤ x, y ≤ 100
        for (int x = 1; x <= 100; ++x) {
            for (int y = 1; y <= 100; ++y) {
                if (freq[x] > 0 && freq[y] > 0) {
                    if (x == y) {
                        // Case where A[i] == A[k]
                        count += (long long)freq[x] * freq[x] * freq[x];
                    } else {
                        // Case where A[i] != A[k]
                        count += (long long)freq[x] * freq[y] * freq[y];
                    }
                }
            }
        }

        // Store the result for this test case
        results.push_back(count);
    }

    return results;
}

int main() {
    int T;
    cin >> T;
    
    vector<pair<int, vector<int>>> testCases(T);
    
    for (int t = 0; t < T; ++t) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        testCases[t] = {N, A};
    }

    // Calculate results for each test case
    vector<long long> results = countTriplets(T, testCases);

    // Output the results
    for (long long result : results) {
        cout << result << endl;
    }

    return 0;
}
