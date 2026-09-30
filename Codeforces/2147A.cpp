#include <bits/stdc++.h>
using namespace std;

// Type Aliases 
using ll = long long;
using db = long double;
using str = string;

// Vectors
#define sort(x) sort(begin(x), end(x))

// Algorithms
bool isPrime(int n) {
    for (int i = 2; i < sqrt(n); i++) {
        if (n%i == 0) return false;
    }
    return true;
}


int main() {
    // Want to go from (0, 0) to (x, y) in a rectangular grid
    // using a sequence of steps.
    
    // Each step: move a positive integer amount of length in either the 
    // x-axis direction or the y-axis direction.
    // Odd-numbered steps are done on the x-axis. Even-numbered steps
    // are done on the y-axis.
    
    // Each step must have a length strictly greater than the length of the 
    // previous step.
    
    // Output the minimum number of steps needed to reach (x, y) or -1 if it is 
    // impossible to reach (x, y)
    
    // Try case x = 5, y = 5.
    // 1 -> 2 -> 4 XX
    
    // Try case x = 5, y = 6. 
    // 5 -> 6 
    
    // Try case x = 4, y = 2.
    // 1 -> 2 -> 3
    
    // Try case x = 1, y = 1.
    // 1 -> k > 2 XX
    
    // x < y: always possible. move 1: x. move 2: y.
    // x = y: not possible. 
    // x > y:
    // ->Cases: x - y > 1 -> YES (3). Otherwise, NO (-1).
    
    // Algorithm:
    // if (x < y) print "2\n";
    // else if (x == y) print "-1\n";
    // else if ((x - y) == 1) print "-1\n";
    // else if (y == 1) print "-1\n";
    // else print "3\n";
    
    int t, x, y;
    cin >> t;
    
    while (t--) {
        cin >> x >> y;
        if (x < y) cout << "2\n";
        else if (x == y) cout << "-1\n";
        else if ((x - y) == 1) cout << "-1\n";
        else if (y == 1) cout << "-1\n";
        else cout << "3\n";
    }
    return 0;
}
