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
    // a + b + c buttons in lab.
    // Each button can only be pressed once.
    // a buttons can only be pressed by Anna.
    // b buttons can only be pressed by Katie.
    // c buttons can be pressed by either.
    // Anna and Katie play a game where they press the buttons.
    // Anna gets the first turn. 
    // The girl that cannot press a button loses.
    // Determine who will win if Anna and Katie play optimally. 
    
    // It is best to press one of the c buttons available to both players. 
    // If that is not true, Anna should press one of the a buttons exclusive to her.
    // Similarly, Katie should press one of the b buttons available to her.
    
    // If c is even, the buttons for both players run out on Katie's turn.
    // Then Katie wins if she has strictly more buttons than Anna.
    // If c is odd, the buttons for both players run out on Anna's turn.
    // Then Katie wins if she has more buttons as Anna.
    
    int t, a, b, c;
    cin >> t;
    
    while (t--) {
        cin >> a >> b >> c;
        if (c%2 == 0) {
            if (b >= a) {
                cout << "Second\n";
                continue;
            }
        } else {
            if (b > a) {
                cout << "Second\n";
                continue;
            }
        }
        cout << "First\n";
    }
    return 0;
}
