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
    // In this problem, a permutation of length n contains 0 to n - 1.
    // MEX: the first non-negative integer that does not appear in a sequence.
    
    // We are given p, a permutation of length n, and a strip of n cells.
    // St. Chroma will paint cell i the color MEX(p_1,...,p_i).
    
    // Given two integers: n and x.
    // Construct a permutation p such that the number of cells in the stip that are
    // painted color x is maximized.
    
    // Clearly, we should have 0,...,x-1 as soon as possible and then 
    // have x be the last value in the permutation.
    
    int t, n, x;
    vector<int> p;
    cin >> t;
    
    while (t--) {
        cin >> n >> x;
        
        // Print 0,...x-1
        for (int i = 0; i <= x-1; i++) cout << i << " ";
        // Print x+1,...,n-1
        for (int i = x + 1; i < n; i++) cout << i << " ";
        // Print x if possible
        if (x < n) cout << x << " ";
        // Skip a line.
        cout << endl;
    }
}
