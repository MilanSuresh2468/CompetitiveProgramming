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
    // "H" prints "Hello , World!".
    // "Q" prints the source code of the program.
    // "9" prints the lyrics of a song. 
    // "+" increments the value stored in the internal accumulator. 
    // Figure out whether executing the program will produce any output. 
    // If a program contains H, Q, or 9, the program produces an output.
    cin.tie(0);
    string p;
    cin >> p;
    
    for (int i = 0; i < p.length(); i++) {
        if (p[i] == 'H' || p[i] == 'Q' || p[i] == '9') {
            cout << "YES";
            return 0;
        }
    }
    
    cout << "NO";
}
