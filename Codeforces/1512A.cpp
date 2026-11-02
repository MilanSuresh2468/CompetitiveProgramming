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
    for (int i = 2; i <= sqrt(n); i++) {
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
    // Array a consists of n (n ≥ 3) integers.
    // One element does not equal the others. Find its index.
    // Find the most common element.
    
    int t, n, curr, elem1, elem2, mostCommonElem;
    vector <int> a;
    cin >> t;
    
    while (t--) {
        a.clear();
        cin >> n;
        for (int i = 0; i < n; i++) cin >> curr, a.pb(curr);
        
        // Find the most common element by looking at the first three elements.
        // Find the element that appears two or more times.
        elem1 = a[0];
        elem2 = a[1];
        if (elem1 == elem2) mostCommonElem = elem1;
        else if (a[2] == elem1) mostCommonElem = elem1;
        else mostCommonElem = elem2;
        
        for (int i = 0; i < n; i++) {
            if (a[i] != mostCommonElem) {
                cout << i + 1 << endl;
                break;
            }
        }
    }
    return 0;
}
