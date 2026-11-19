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
    // There are n columns of toy cubes. The i-th column contains a_i cubes. 
    // Gravity switches from pulling the cubes downwards to pulling the cubes to the right side
    // of the box. 
    // Find the amount of cubes in each of the n columns after the gravity switch.
    
    cin.tie(0);
    int n, curr;
    vector <int> a(100);
    cin >> n;
    
    // The program runs in O(n) instead of O(nlogn) if we sort by counting.
    for (int i = 0; i < n; i++) {
        cin >> curr;
        a[curr - 1]++;
    }
    
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < a[i]; j++) {
            cout << " " << i + 1;
        }
    }
    
}
