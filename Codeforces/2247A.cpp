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
    for (int i = 2; i < sqrt(n); i++) {
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
    // array a: length n, elements are all 1 or -1. 
    // Operation: 
    // ->Choose 1 ≤ i ≤ n - 1.
    // ->Assign a_i = -a_i and a_{i+1} = -a_{i+1}.
    // Determine whether it is possible to make a's elements sum to 0.
    
    // Previous strategy: possible to make a sum to 0 <=> n mod 2 = 0 and the number of 1's 
    // and -1's are equal.
    // This fails: -1 -1 -1 -1 has 0 1's and 4 -1's, but it is possible to make a's 
    // elements sum to 0. 
    
    // Test Case: 4
    // -1 -1 -1 -1
    // Operation: choose i = 1. 
    // a's elements sum to 0.
    
    // Operations can be chained together: doing operations on i = 1, i = 2,..., i = n
    // inverts i = 1 and i = n + 1. 
    // It is possible to invert any two elements while having the others remain constant.
    
    // An operation adds 4 to a's sum if the two elements are negative and decreases a's sum
    // by 4 if the two elements are positive.
    // If one element is positive and one element is negative, then the operation does nothing.
    
    // Case 1: (sum of a) mod 4 = 0. 
    // We can use the operations to get the sum to 0.
    // Case 2: (sum of a) mod 4 = 1. 
    // We cannot use the operations to get the sum to 0. 
    // Cases 3 and 4 are similar to 1.
    
    // Rule: check if the sum is divisible by 4. 
    
    int t, n, curr, sum;
    
    cin >> t;
    
    while (t--) {
        cin >> n;
        sum = 0;
        
        while (n--) {
            cin >> curr;
            sum += curr;
        }
        
        if (sum%4 == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
