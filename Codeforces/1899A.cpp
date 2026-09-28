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
    // Vanya and Vova play a game.
    // Given integer n.
    // On their turn, the player can add 1 to the current integer
    // or subtract 1. Vanya starts.
    // If after Vanya's move, the integer is divisible by 3, then he wins.
    // Otherwise, Vova wins.
    // Possibilities: n%3 == 0, n%3 == 1, n%3 == 2 
    // Vanya wins if n%3 == 1 or n%3 == 2. 
    
    int t, n;
    cin >> t;
    
    while (t--) {
        cin >> n;
        if (n%3 == 1 || n%3 == 2) cout << "First\n";
        else cout << "Second\n";
    }
    return 0;
}
