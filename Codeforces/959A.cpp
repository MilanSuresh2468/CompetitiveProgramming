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
bool isPrime(ll n) {
    for (ll i = 2; i <= sqrt(n); i++) {
        if (n%i == 0) return false;
    }
    return true;
}

int intPow(ll x, ll y) {
    ll result = 1;
    for (int i = 0; i < y; i++) result *= x;
    return result;
}


int main() {
    // Ehab chooses n (1 ≤ n ≤ 10^9).
    // Mahmoud and Ehab take turns (Mahmoud starts).
    // Turn:
    // -> Subtract a (1 ≤ a ≤ n) from n. 
    // -> Mahmoud must pick an even number.
    // -> Ehab must pick an odd number. 
    // A player loses if they can't pick a number satisfying the conditions. 
    // Output the name of the player who wins under optimal play.
    
    // Say n is even. Mahmoud can let a = n. Ehab has no number to pick on his turn, so Mahmoud wins.
    // Say n is odd. Mahmoud must pick a = 2k < n = 2q + 1. On Ehab's turn, n = 2q + 1 - 2k = 2(q-k) + 1.
    // Ehab can pick n and win. 
    
    // Ehab wins if n is odd. Mahmoud wins if n is even.
    
    int n;
    cin >> n;
    
    if (n%2 == 0) cout << "Mahmoud";
    else cout << "Ehab";
}
