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
    int t, n, curr;
    bool flag;
    vector <int> a;
    cin >> t;
    
    while (t--) {
        cin >> n;
        a.clear();
        flag = true;
        
        for (int i = 0; i < n; i++) {
            cin >> curr;
            a.pb(curr);
        }
        sort(a);
        
        for (int i = 1; i < n; i++) {
            if (a[i] == a[i - 1]) {
                cout << "NO\n";
                flag = false;
                break;
            }
        }
        
        if (flag) cout << "YES\n";
    }
    return 0;
}
