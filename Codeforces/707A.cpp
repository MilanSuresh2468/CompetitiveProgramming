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
    // First line: n m (1≤n,m≤100) - the number of photo piaxel matrix rows and columns 
    // n lines with m characters follow. 
    // Six pixel colors: C, M, Y, W, G, and B.
    // Print "#Black&White" if the block only has black and white pixels. Otherwise, print 
    // "#Color".
    
    int n, m;
    char curr;
    cin >> n >> m;
    
    for (int i = 0; i < n * m; i++) {
        cin >> curr;
        if (curr != 'B' && curr != 'W' && curr != 'G') {
            cout << "#Color";
            return 0;
        }
    }
    
    cout << "#Black&White";
}
