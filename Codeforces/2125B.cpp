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

ll intPow(int x, int y) {
    ll result = 1;
    for (int i = 0; i < y; i++) result *= x;
    return result;
}


int main() {
    // First line of input: t (1≤t≤10^4).
    // Next t lines: a b k (1≤a,b,k≤10^18).
    // Output minimum total cost of operations to go from (a,b) to (0,0).
    // Operation: 
    // ->Choose dx and dy to be numbers from 0 to k.
    // ->Move the robot dx left and dy down.
    // ->If we used (dx, dy) for the first time, the operation costs 1.
    // ->Otherwise, the operation costs 0.
    
    // Clearly, we can use (1, 1) until 1 coordinate is 0 and then use
    // (0, 1) or (1, 0). The minimum total cost to get to (0,0) is ≤ 2.
    
    // If gcd(a, b) ≠ 1, we can divide a and b by gcd(a, b) to get dx and dy. 
    // We only need to use that pair to get to (0,0). This works if a/gcd(a,b),
    // b/gcd(a,b) ≤ k. Cost: 1. 
    
    // If a,b ≤ k, we can use (a, b) as the pair and get to (0,0) with a cost of 1.
    
    // Question: How do we efficiently determine if a and b are coprime? 
    // It may take 10^9 operations to determine is a is prime since isPrime runs in 
    // O(√x). 
    
    // Test Case 1: a = 3, b = 5, k = 15. 
    // Apply the operation (3,5) once. The cost of the operation will be 1.
    
    // Test Case 2: a = 2, b = 3, k = 1. 
    // Apply the operations (1,1), (0,1), and (1,1). After the first operation, the robot
    // will be at the cell (1,2). After the second one, the robot will be at the cell
    // (1,1). After the third one, the robot will be at the cell (0,0).
    // The cost of the first two operations is 1, while the cost of the third is 0 
    // since the first operation already used (1,1). We get to (0,0) with a cost of 2.
    
    // Test Case 3: a = 12, b = 18, k = 8. 
    // Apply the operation (4,5) three times in a row to get to (0,0) with a cost of 1.
    
    // Test Case 4: a = 9, b = 7, k = 5.
    // Apply the operations (4,2) and (5,5) to get to (0,0) with a cost of 2. 
    
    // Observations:
    // 1. Misha can get to (0,0) with a cost of 1 if a/gcd(a,b), b/gcd(a,b) ≤ k. 
    // 2. The minimum cost to get to (0,0) ≤ 2. 
    // 3.
    
    // Official Solution:
    // gcd is a built-in function, which makes solving the problem easy.
    
    ll t, a, b, k;
    cin >> t;
    
    while (t--) {
        cin >> a >> b >> k;
        if (max(a/gcd(a,b), b/gcd(a,b)) <= k) cout << 1 << endl;
        else cout << 2 << endl;
    }
    
    return 0;
}
