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
    // You are given three digits a, b, c. Two of them are equal, but the third one is different
    // from the other two. Find the value that occurs exactly once. 
    
    // First Line - t: the number of test cases
    // Each Test Case: a, b, c (0 ≤ a,b,c ≤ 9).

    cin.tie(0);
    int a, b, c, t;
    cin >> t;
    
    while (t--) {
        cin >> a >> b >> c;
        if (a != b && a != c) {
            cout << a << endl;
        } else if (b != a && b != c) {
            cout << b << endl;
        } else {
            cout << c << endl;
        }
    }
}
