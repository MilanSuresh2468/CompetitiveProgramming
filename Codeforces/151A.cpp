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
    // n: #friends
    // k: #bottles
    // l: #mm of drink per bottle 
    // c: #limes 
    // d: #slices/lime 
    // p: #grams of salt  
    // nl: milliliters required for a drink
    // np: grams of salt required for a drink. 
    // A drink requires nl milliliters of soda, np grams of salt, and a slice of lime. 
    
    int n, k, l, c, d, p, nl, np; // input 
    int quantity1; // the number of toasts (with 1 friend) that can be made with the amount
    // of the drink available.
    int quantity2; // the number of toasts (with 1 friend) that can be made with the lime
    // slices available.
    int quantity3; // the number of toasts (with 1 friend) that can be made with the salt available.
    
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    
    quantity1 = (k*l)/nl;
    quantity2 = c*d; 
    quantity3 = p/np;
    
    
    cout << min(min(quantity1, quantity2), quantity3)/n;
    
    
    return 0;
}
