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
    // n problems numbered 1 to n. 
    // The first and last problems should be easy.
    // Operation: swap any two problems. 
    
    int t, n, curr, count;
    vector <int> a;
    cin >> t;
    
    while (t--) {
        cin >> n; 
        count = 0;
        a.clear();
        
        for (int i = 0; i < n; i++) {
            cin >> curr;
            if (!curr) count++;
            a.pb(curr);
        }
        
        if (count < 2) {
            cout << -1 << endl;
        } else {
            cout << 2 - !a[0] - !a[n - 1] << endl;
        }
    }
    return 0;
}
