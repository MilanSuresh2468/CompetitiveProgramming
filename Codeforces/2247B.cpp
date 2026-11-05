#include <bits/stdc++.h>
using namespace std;

// Type Aliases 
using ll = long long;
using db = long double;
using str = string;

// Vectors
#define sort(x) sort(begin(x), end(x))
#define erase(x, i) x.erase(x.begin() + i)
#define pb push_back

// Algorithms
bool isPrime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n%i == 0) return false;
    }
    return true;
}

int intPow(int x, int y) {
    int result = 1;
    for (int i = 0; i < y; i++) result *= x;
    return result;
}


int main() {
    // Line 1: 1 ≤ t ≤ 10^4.
    // Next t lines: n k m (1 ≤ k ≤ n ≤ 2*10^5, 1 ≤ m ≤ 10^9)
    // An array a of n positive integers is good if we need at least k consecutive 
    // elements to get a sum divisible by m.
    // Find any good array a or determine that no such array exists.
    
    // Official Solution: If m < k, then the answer is -1 because it is well known that 
    // in any array with m elements, there is a nonempty subarray with sum divisible by
    // m. 
    // Proof: Consider remainders of prefix sums by m. There are m + 1 prefix sums, and
    // only m possible remainders by modulo m. Therefore, two of the prefix sums have
    // the same remainder and in the segment between those two prefix sums the
    // sum is divisible by m.
    
    // Otherwise, the solution is to make a_j = 1 for all j such that j mod k ≠ 0, and a_j
    // = m - k + 1 for j is equivalent to 0 mod k. In this construction, every subarray of
    // length k has the sum of exactly m, and every subarray whose length is less than k 
    // obviously has a sum that is greater than 0 and less than m. Therefore, it cannot 
    // be divisible by m. 
    
    int t, n, k, m;
    cin >> t;
    
    while (t--) {
        cin >> n >> k >> m;
        
        if (m < k) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int i = 0; i < n; i++) {
                if (i%k == 0) {
                    cout << m - k + 1 << " ";
                } else {
                    cout << 1 << " ";
                }
            }
            cout << endl;
        }
    }
    return 0;
}
