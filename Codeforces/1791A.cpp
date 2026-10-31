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
    // Check if a lowercase Latin character appears in the string codeforces.
    int t;
    char c;
    cin >> t;
    
    while (t--) {
        cin >> c;
        // Is the letter c, o, d, e, f, r, or s?
        if (c == 'c' || c == 'o' || c == 'd' || c == 'e' || c == 'f' || c == 'r' || c == 's') {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
