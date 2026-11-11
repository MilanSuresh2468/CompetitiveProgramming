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
    // Is m the next prime number after n?
    int n, m;
    cin >> n >> m;
    
    // If there are any prime numbers from n+1 to m-1, then m is not the next prime number
    // after n.
    for (int i = n + 1; i < m; i++) {
        if (isPrime(i)) {
            cout << "NO";
            return 0;
        }
    }
    
    // If m is prime, then m is the next prime number after n. If m is not prime, then m 
    // is not the next prime number after n. 
    if (isPrime(m)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
} 
