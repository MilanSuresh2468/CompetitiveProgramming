#include <bits/stdc++.h>
using namespace std;

// Type Aliases 
using ll = long long;
using db = long double;
using str = string;

// Vectors
#define sort(x) sort(begin(x), end(x))
#define erase(x, i) x.erase(x.begin() + i)

// Algorithms
bool isPrime(int n) {
    for (int i = 2; i < sqrt(n); i++) {
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
    int t, a, b, x, ans, ops;
    cin >> t;
    
    while (t--) {
        cin >> a >> b >> x;
        ans = max(b, a) - min(b, a);
        ops = 0;
        
        
        while (b != 0 || a != 0) {
            ops++;
            if (a > b) a /= x;
            else b /= x;
            ans = min(ans, ops + max(b, a) - min(b, a));
        }
        
        cout << ans << endl;
    }
    return 0;
}
