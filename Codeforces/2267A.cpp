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
    // string s of n letters
    // char c 
    // With one coin, he can replace
    // an element of s with c. 
    // Compute the min coins needed 
    // to turn s into a palindrome.
    
    int t, n, numCoins;
    char c;
    string s;
    
    cin >> t;
    while (t--) {
        cin >> n >> c >> s;
        numCoins = 0;
        if (s.length() == 1) {
            cout << 0 << endl;
        } else if (s.length()%2 == 0) {
            for (int i = 0; i < s.length()/2; i++) {
                if (s[i] != s[s.length() - 1 - i]) {
                    if (s[i] == c || s[s.length() - 1 - i] == c) {
                        numCoins++;
                    } else {
                        numCoins += 2;
                    }
                } 
            }
            
            cout << numCoins << endl;
        } else {
           for (int i = 0; i < (s.length() - 1)/2; i++) {
               if (s[i] != s[s.length() - 1 - i]) {
                   if (s[i] == c || s[s.length() - 1 - i] == c) {
                       numCoins++;
                   } else {
                       numCoins += 2;
                   }
               }
           }
           cout << numCoins << endl;
        }
    }
    
    return 0;
}
