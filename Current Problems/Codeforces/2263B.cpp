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
    // B is a 2D matrix. f(B) denotes the set of the minimum element of each row and column
    // of B. 
    
    // Show farmer John an n x n matrix A of each number from 1 to n^2 such that |f(A)| = k, or
    // state that it is impossible.
    
    // Test Case 1: n = 3, k = 0 - It is impossible to construct a 3 x 3 matrix where f(A) is
    // empty (|f(a)| = 0)? No. 
    
    // Test Case 2: n = 3, k = 5 - Is it possible to construct a 3 x 3 matrix where |f(A)| = 5?
    // 2 1 4
    // ^ ^ ^
    // | | |
    // 8 5 9 -> 5
    // 6 3 7 -> 3
    // 2 1 4 -> 1
    // f(A) = {1, 3, 5, 2, 4}.
    // |f(A)| = 5. 
    
    // Test Case 3: n = 5, k = 5 - Is it possible to construct a 5 x 5 matrix where |f(A)| = 5?
    // 4  1  5  2  3
    // ^  ^  ^  ^  ^
    // |  |  |  |  |
    // 16 14 17 15 3 -> 3
    // 25 22 5  23 24-> 5
    // 8  1  9  6  7 -> 1
    // 4  18 21 19 20-> 4
    // 12 10 13 2  11-> 2
    // f(A) = {4, 1, 5, 3, 3}.
    // |f(A)| = 5. 
    
    // Test Case 4: n = 4, k = 3 - Is it possible to construct a 4 x 4 matrix where |f(A)| = 3?
    // Let's try. 
    // 1
    //   2
    //     3 
    //       4 
    // It seems like we cannot make a solution if k < n. 
    
    // What if k = n? 
    // Make a diagonal 1 to n. 
    // Clearly, all of the row and column minimums are now one of those numbers.
    // |f(A)| = n. 
    
    // What if k = 2n? 
    // Impossible. 1 must be the minimum for a row and a column. 
    
    // We cannot make a solution if k < n or k = 2n.
    
    // What if n < k < 2n? 
    // Top row is 1 to n.
    // Fill in the first number of row 2...n with n+1...k. 
    
    // Soution idea 1: 
    // If k < n or k = 2n, print -1.
    // Otherwise, the top row is 1 to n.
    // Fill in the first number of row 2...n with n+1...k.
    // Fill in the rest of the numbers.
    
    // 1 2 3 4 5 
    // 6 7 8 9 10 
    // 11 12 13 14 15 
    // 16 17 18 19 20 
    // 21 22 23 24 25
    // Solution idea 1 does not work when n = 5, and k = 5.
    
    // Official Solution:
    // 
    
    int t, n, k, curr;
    cin >> t;
    
    while (t--) {
        cin >> n >> k;
        
        if (k < n || k == 2*n) {
            cout << -1 << endl;
            continue;
        }
        
        int a[n][n] = {0};
        
        // Fill the top row with 1 to n.
        for (int i = 0; i < n; i++) {
            a[0][i] = i + 1;
        }
        
        // Fill in the first number of row 2...n with n+1...k.
        for (int i = n; i < k; i++) {
            a[i - n + 1][0] = i + 1;
        }
        
        // Fill in the rest of the numbers.
        curr = k + 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 0) {
                    a[i][j] = curr;
                    curr++;
                }
            }
        }
        
        // Print the array.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[i][j] << " ";
            }
            
            cout << endl;
        }
    }
    return 0;
}
