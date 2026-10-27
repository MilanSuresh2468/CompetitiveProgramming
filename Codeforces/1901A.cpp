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
    // Want to travel from point 0 to point x to point 0 on a number line. 
    // Traveling 1 unit costs 1 liter of gasoline. 
    // The car is fully fueled at point 0.
    // n gas stations at a_1,a_2,...,a_n. When I arrive at a gas station, I fully refuel
    // my car. 
    // Minimum volume of gas tank needed to travel from 0 to x to 0.
    
    // max(a_1, a_2 - a_1, a_3 - a_2,...,a_n - a_1, 2(x - a_n))
    
    int t, n, x, curr, max;
    vector <int> a;
    cin >> t;
    
    while (t--) {
        cin >> n >> x;
        a.clear();
        a.pb(0);
        max = 0;
        
        for (int i = 0; i < n; i++) {
            cin >> curr;
            a.pb(curr);
        }
        
        for (int i = 1; i <= n; i++) {
            if ((a[i] - a[i-1]) > max) max = a[i] - a[i-1];
        }
        
        if (2*(x-a[n]) > max) max = 2*(x-a[n]);
        
        cout << max << endl;
    }
    return 0;
}
