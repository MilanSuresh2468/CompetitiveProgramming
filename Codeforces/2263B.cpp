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
    // Each number can be the minimum of at most one row and one column, so we must have
    // n ≤ k. Additionally, 1 is always the minimum element of its row and column, so
    // we have k ≤ 2n - 1. We claim that it is always possible to construct a satisfying
    // matrix for n ≤ k ≤ 2n - 1. Let x = k + 1 - n.
    // We have k = x + n - 1. => n ≤ x + n - 1.
    // We have 2x = 2(k + 1 - n) = 2k + 2 - 2n ≤ 2k + 2 - k ≤ 2. Hence 2x ≤ k if k ≥ 2. 
    // ≤ 2n - 1 => 1 ≤ x ≤ n. 
    // Place 1,...,x in the first row. 
    // Place x+1,...,2x-1 in the first column below the 1.
    // Place 2x,...,k on the main diagonal outside of the top-left x *x* x box
    // Each row or column contains at least one of these numbers and achieves |f(A)| = k, so
    // we can fill in the blank spaces with numbers k + 1,...,n^2 however we wish.
    
    // Algorithm: 
    // If k < n or k = 2n, print -1 and stop.
    // If n = 1 and k = 1, print 1 and stop. 
    // Else, let x = k + 1 - n. 
    // Fill in the top row with 1,...,x.
    // Place x+1,...,2x-1 in the first column below the 1.
    // Place 2x,..,k on the main diagonal outside of the top left x *x* x box.
    // Fill in the rest of the spaces with the remaining numbers row by row.
    
    // Test case 3 (n = 5, k = 5) does not work.
    // What my code produces:
    /* 1 32764 1821088032 32764 6 
       7 2 8 9 10 
       11 12 3 13 14 
       15 16 17 4 18 
       19 20 21 22 5 
    */
    // What it should produce:
    // 1 6 7 8 9
    // 10 2 11 12 13 
    // 14 15 3 16 17 
    // 18 19 20 4 21 
    // 22 23 24 25 5
    // What does the matrix look like after we do the three steps before the last step?
    /*1 32765 1622510864 32765 0 
      0 2 0 0 0 
      0 0 3 0 0 
      0 0 0 4 0 
      0 0 0 0 5*/
    // When did a_{0,1}, a_{0,2}, and a_{0,3} become those numbers?
    // Those elements were those numbers after int a[n][n] = {0}.
    // Changing the line to int a[n][n]; introduces even more irrelevant numbers.
    // For a 2D array whose size is defined via constants, we
    // can use a similar approach: int marr[10][10] = {}.
    // However, our 2D array's size is defined via variables, so we must use a different approach.
    // Idea: just manually fill in the array with 0's.
    
    
    int t, n, k, x, curr;
    cin >> t;
    
    while (t--) {
        cin >> n >> k;
        
        if (k < n || k == 2*n) {
            cout << -1 << endl;
            continue;
        } else if (n == 1 && k == 1) {
            cout << 1 << endl;
            continue;
        }
        
        int a[n][n] = {};
        x = k + 1 - n;
        
        // Manually fill in a with 0's.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = 0;
            }
        }
        
        // Fill in the top row with 1,...,x.
        
        for (int i = 0; i < x; i++) {
            a[0][i] = i + 1;
        }
        
        // Place x+1,...,2x-1 in the first column below the 1.
        for (int i = 1; i <= x - 1; i++) {
            a[i][0] = i + x;
        }
        
        // Place 2x,..,k on the main diagonal outside of the top left x *x* x box.
        for (int i = x; i <= n - 1; i++) {
            a[i][i] = x + i;
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
