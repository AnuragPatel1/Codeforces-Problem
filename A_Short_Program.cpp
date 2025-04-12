#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    // Initial masks:
    // and_mask starts as all bits 1 (1023 is 1111111111 in binary for 10 bits).
    // or_mask and xor_mask start as 0.
    int and_mask = 1023;
    int or_mask = 0;
    int xor_mask = 0;
    
    // Process each operation
    for (int i = 0; i < n; ++i) {
        char op;
        int x;
        cin >> op >> x;
        
        if (op == '&') {
            // Update AND and OR masks
            and_mask &= x;
            or_mask &= x;  // AND limits the OR mask as well
        } else if (op == '|') {
            // Update OR mask
            or_mask |= x;
        } else if (op == '^') {
            // Update XOR mask
            xor_mask ^= x;
        }
    }
    
    // Output the minimal set of operations
    cout << 3 << endl;
    cout << "^ " << xor_mask << endl;  // Apply XOR mask first
    cout << "| " << or_mask << endl;   // Apply OR mask second
    cout << "& " << and_mask << endl;  // Apply AND mask last

    return 0;
}
