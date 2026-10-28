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
    // Array a of length n.
    // Determine whether it is possible to color a's elements in blue and red such that
    // the sums of the red elements and blue elements are equal, and there is at least
    // one red element and one blue element.
    // [1,2,4,3,2,3,5,4]->The sum of the blue elements is 6, and the sum of the red elements
    // is 18. 
    
    // Sum of total elements should be even.
    
    int t, n, curr, sum;
    cin >> t;
    
    while (t--) {
        cin >> n;
        sum = 0;
        
        while (n--) {
            cin >> curr;
            sum += curr;
        }
        
        if (sum%2 == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
