#include <bits/stdc++.h>
using namespace std;

// Type Aliases 
using ll = long long;
using db = long double;
using str = string;

// Vectors
#define sort(x) sort(begin(x), end(x))

// Algorithms
bool isPrime(int n) {
    for (int i = 2; i < sqrt(n); i++) {
        if (n%i == 0) return false;
    }
    return true;
}


int main() {
    // Permutation: sequence of integers p_1, p_2, ..., p_n of n distinct
    // positive integers that do not exceed n.
    
    // A perfect permutation is a permutation p where for any i (1 <= i <= n),
    // p_p_i = i and p_i != i.
    
    // Print any perfect permutation of size n for the given n.
    // Print -1 if a perfect permutation does not exist. 
    
    // Example: n = 1.
    // The only way to arrange 1...1 is 1.
    // i = 1: p_p_i = p_1 = 1. p_i = p_1 = 1.
    // p_p_i = i. p_i = i. 
    // There is no perfect permutation, so the program should print -1. 
    
    // Example: n = 2.
    // Two possible permutations: 1, 2 and 2, 1. 
    // Check 2, 1.
    // i = 1: p_p_i = p_p_1 = p_2 = 1. p_i = p_1 = 2. 
    // p_p_i = i. p_i != i. 
    // i = 2: p_p_i = p_p_2 = p_1 = 2. p_i = p_2 = 1. 
    // p_p_i = i. p_i != i. 
    // 2, 1 is a perfect permutation, so the program should print 2, 1. 
    
    // Example: n = 4.
    // One possible permutation of length n = 4 is 2, 1, 4, 3.
    // Check 2, 1, 4, 3.
    // i = 1: p_p_i = p_p_1 = p_2 = 1. p_i = p_1 = 2.
    // p_p_i = i. p_i != i.
    // i = 2: p_p_i = p_p_2 = p_1 = 2. p_i = p_2 = 1.
    // p_p_i = i. p_i != i.
    // i = 3: p_p_i = p_p_3 = p_4 = 3. p_i = p_3 = 4.
    // p_p_i = i. p_i != i.
    // i = 4: p_p_i = p_p_4 = p_3 = 4. p_i = p_4 = 3.
    // p_p_i = i. p_i != i.
    // 2, 1, 4, 3 is a perfect permutation, so the program should print 
    // 2, 1, 4, 3.
    
    // This was a weird problem, and I sat there staring at test cases
    // for way too long. 
    
    // Editorial by fdoer:
    // If we have a permutation p such that p_i = i (p = 1, 2, ..., n), then
    // p_p_i = i. Now we must change the permutation to satisfy p_i != i. 
    // Swap every two consecutive elements. Formally, for each k where 2k <= n,
    // swap p_{2k-1} and p_{2k}. p = 2, 1, 4, 3, ..., n, n-1. It is easy to see 
    // that the obtained permutation satisfies both equations for every n.
    // We have one exception: when n is odd, there is no answer, and we should print
    // -1. 
    
    // Algorithm:
    // If n is even, print 2, 1, 4, 3, ..., n, n - 1.
    // If n is odd, print -1.
    
    int n;
    cin >> n;
    
    if (n%2 == 0) {
        for (int i = 1; i < n; i+= 2) {
            cout << i + 1 << " " << i << " ";
        }
    } else {
        cout << -1;
    }
    return 0;
}
