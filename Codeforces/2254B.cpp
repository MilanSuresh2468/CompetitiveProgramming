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
    // s is a string of length n (n ≥ 3).
    // f(s) compresses all blocks of a character into one character.
    // Delete one character s_i (2 ≤ i ≤ n - 1).
    // Find the minimum possible value of |f(s')|.
    
    // If we delete a character in a block of length ≥ 2, |f(s')| = f(s).
    // If we delete a block of length 1, |f(s')| < f(s).
    // ->If deleting the character merges two blocks, |f(s')| = |f(s)| - 2.
    // ->If deleting a character does not merge two blocks, |f(s')| = |f(s)| - 1.
    
    // Algorithm:
    // ->Find |f(s)|.
    // ->Look for a block of length 1 surrounded by two same character blocks. If one is found, 
    // print |f(s)| - 2 and stop.
    // -> Look for a block of length 1 not surrounded by two same character blocks. If one is found,
    // print |f(s)| - 1 and stop.
    // -> Print |f(s)|.
    
    int t, n, length_of_f_of_s;
    bool flag;
    string s;
    
    cin >> t;
    while (t--) {
        
        // Take in input for each test case.
        cin >> n >> s;
        flag = false;
        
        // ->Find |f(s)|.
        length_of_f_of_s = s.length();
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i-1]) length_of_f_of_s--;
        }
        
        // ->Look for a block of length 1 surrounded by two same character blocks. If one is found, 
        // print |f(s)| - 2 and stop.
        for (int i = 1; i < s.length() - 1; i++) {
            // Is s[i] a block of length 1 surrounded by two same character blocks?
            if (s[i] != s[i - 1] && s[i-1] == s[i+1]) {
                cout << length_of_f_of_s - 2 << endl;
                flag = true;
                break;
            }
        }
        if (flag) continue;
        
        // -> Look for a block of length 1 not surrounded by two same character blocks. If one is found,
        // print |f(s)| - 1 and stop.
        for (int i = 1; i < s.length() - 1; i++) {
            // Is s[i] a block of length 1 not surrounded by two same character blocks?
            if (s[i] != s[i-1] && s[i] != s[i+1]) {
                cout << length_of_f_of_s - 1 << endl;
                flag = true;
                break;
            }
        }
        if (flag) continue;
        
        // -> Print |f(s)|.
        cout << length_of_f_of_s << endl;
    }
    
    return 0;
}
