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
    // Check if string s of length 3 is equal to "YES" where each letter can be
    // in any case.
    
    int t;
    string s;
    cin >> t;
    
    while (t--) {
        cin >> s;
        if ((s[0] == 'y' || s[0] == 'Y') && (s[1] == 'E' || s[1] == 'e'
) && (s[2] == 's' || s[2] == 'S')) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
