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
    cin.tie(0);
    
    // Volodya writes down the odd inteers from 1 to n and then the even integers from 1 to n, both
    // in ascending order. What number is at position k? 
    // Input: n k (1 ≤ k ≤ n ≤ 10^12).
    // Output: The number at position k.
    
    // n is even: 
    // The first n/2 numbers are 1,3,...,n-1.
    // The last n/2 numbers are 2,4,...,n.
    // If k ≤ n/2, the number at position k is 2k - 1. 
    // If k > n/2, the number at position k is 2(k - n/2) = 2k - n - 1.
    
    // n is odd:
    // The first (n+1)/2 numbers are 1,3,...,n. 
    // The last n - (n+1)/2 = 2n/2 - (n+1)/2 = (n-1)/2 numbers are 2,4,..,n-1. 
    // If k ≤ (n+1)/2, the number at position k is 2k - 1. 
    // If k > (n+1)/2, the number at position k is 2*(k - (n+1)/2) = 2k - (n+1) = 2k - n - 1. 
    
    ll n, k;
    cin >> n >> k;
    
    if (n%2 == 0) {
        if (k <= n/2) cout << 2*k - 1;
        else cout << 2*k - n;
    } else {
        if (k <= (n+1)/2) cout << 2*k - 1;
        else cout << 2*k - n - 1;
    }
    
    // Fails on test case 5: 8 5. 
    // The output should be 2, but the program outputs 1. 
    // Arrangement of numbers: 1 3 5 7 2 4 6 8
}
