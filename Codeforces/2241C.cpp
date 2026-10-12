#include <bits/stdc++.h>
using namespace std;

// Type Aliases 
using ll = long long;
using db = long double;
using str = string;

// Vectors
#define sort(x) sort(begin(x), end(x))
#define erase(x, i) x.erase(x.begin() + i)

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
    // binary string s of length n 
    // Operation: Delete one character from a palindrome substring of length at least 2.
    // Find the minimum achievable length of s.
    
    // Test Case 1: 0000 -> select s_1, s_2. delete s_1. -> 000
    // 000 -> select s_1, s_2. delete s1. -> 00
    // 00 -> select s_1, s_2. delete s_1. -> 0
    // Min length: 1
    
    // Test Case 2: 110 -> select s_1, s_2. delete s_1. -> 10
    // Can't make another palindrome. 
    // Min length: 2.
    
    // Test Case 3: 110011 -> 10011 -> 1001 -> 101 -> 11 -> 1 
    
    // Test Case 4: 101100 -> 10110 -> 1010 -> 101 -> 11 -> 1
    // NEED TO GET RID OF ALL 0's 
    
    // Binary strings of length 2: 00, 01, 10, 11 
    // Palindromes of length 2: 00, 11.
    
    // Binary strings of length 3: 000, 001, 010, 011, 100, 101, 110, 111
    // Palindromes of length 3: 000, 010, 101, 111
    
    // Solution Idea: 
    
    // Let c be the number of positions i such that s_i ≠ s_{i+1}.
    
    // If c = 0, all characters are equal. The whole string is a paildrome, and we 
    // can delete characters until one remains.
    
    // If c = 1, the string is two contiguous blocks of equal characters. Any palindrome 
    // of length at least 2 must be contained entirely inside one of these blocks. 
    // We can reduce both blocks to one character. The minimum achievable length is 2. 
    
    // If c >= 2, the string has at least three blocks. We shrink every block to length 1. 
    // The string is now alternating. The last three characters are a palindrome. Repeatedly
    // delete the first character of the palindrome until we are left with 3 characters in s.
    // Delete the middle character. Delete the first character.
    
    int t, n, count;
    string s;
    cin >> t;
    
    while (t--) {
        cin >> n >> s; 
        count = 0;
        
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1]) count++;
        }
        
        if (count == 1) cout << 2 << endl;
        else cout << 1 << endl;
    }
    

    return 0;
}
