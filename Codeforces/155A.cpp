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
    int n, curr, min, max, amazingPerformances = 0;
    
    cin >> n;
    n--;
    cin >> min;
    max = min;
    
    while (n--) {
        cin >> curr;
        
        if (curr > max) {
            max = curr;
            amazingPerformances++;
        } else if (curr < min) {
            min = curr;
            amazingPerformances++;
        }
    }
    
    cout << amazingPerformances;
    return 0;
}
