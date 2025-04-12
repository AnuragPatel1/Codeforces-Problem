#include <bits/stdc++.h> // Includes all standard libraries (not recommended for large projects).
using namespace std;
int n;  vector<long long> v; // Vector to store the input numbers.
// Structure to define a custom stack that also tracks the GCD of its elements.
struct Stack {
    vector<long long> stk; // Stack to store the elements.
    vector<long long> val = {0}; // Tracks GCD of elements. Initialized with 0.

    // Pushes a new element to the stack and updates the GCD.
    void push(long long x) {
        stk.push_back(x); // Add element to stack.
        val.push_back(__gcd(val.back(), x)); // Update GCD with the new element.
    }

    // Returns the GCD of the current stack elements.
    long long top() {
        return val.back(); // Top of the `val` vector holds the current GCD.
    }

    // Removes the top element from the stack and updates the GCD.
    long long pop() {
        long long x = stk.back(); // Get the top element.
        stk.pop_back(); // Remove it from the stack.
        val.pop_back(); // Remove its corresponding GCD value.
        return x;
    }

    // Checks if the stack is empty.
    bool empty() {
        return stk.empty();
    }
};

// Two stacks for implementing the sliding window logic.
Stack s1, s2;

// Function to remove elements from the sliding window.
void remove() {
    // If `s1` is empty, refill it by popping elements from `s2`.
    if (s1.empty()) {
        while (!s2.empty()) {
            s1.push(s2.pop());
        }
    }
    // Remove the top element of `s1`.
    s1.pop();
}

int main() {
    // Read the size of the array.
    scanf("%d", &n); 
    v.resize(n); // Resize vector to hold `n` elements.
    
    // Read the array elements.
    for (auto &x : v) scanf("%lld", &x);

    int l = 0; // Left boundary of the sliding window.
    int ans = n + 1; // Initialize answer to a value larger than any possible subarray length.

    // Iterate through the array.
    for (int i = 0; i < n; ++i) {
        s2.push(v[i]); // Add the current element to `s2`.

        // Check if the combined GCD of both stacks is 1.
        while (__gcd(s1.top(), s2.top()) == 1) {
            remove(); // Remove the leftmost element to shrink the window.
            ans = min(ans, i - l + 1); // Update the minimum subarray length.
            l++; // Move the left boundary of the window.
        }
    }

    // If no valid subarray is found, set answer to -1.
    if (ans > n) ans = -1;

    // Output the result.
    printf("%d\n", ans);
    return 0;
}
