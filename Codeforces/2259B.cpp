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
    // You are given an array a_1, a_2,..., a_n. 
    // You may perform the following operation:
    // For all indices 1 <= i <= n, a_i = |a_i - 2|.
    // Find the max frequency of any integer in a after performing
    // the operation some (possibly zero) amount of times.
    
    // Example: a = [1, 3] -> [1, 1]. 
    
    // a = [1, 10, 100, 1000, 100,000]
    // It is somehow possible to get 3 copies of one integer (?).
    
    
    // 1 is always 1.
    // 2 -> 0 -> 2 -> 0
    // 3 -> 1 -> 1 -> 1 
    // 4 -> 2 -> 0 -> 2
    // 5 -> 3 -> 1 -> 1 -> 1 
    // 6 -> 4 -> 2 -> 0 -> 2 
    
    // countOdd: #elements of a that are equivalent to 1 mod 2.
    // countTwo: #elements of a that are equivalent to 2 mod 4.
    // countZero: #elements of a that are equivalent to 0 mod 4.
    
    int t, n, curr, countOdd, countTwo, countZero;
    cin >> t;
    
    while (t--) {
        cin >> n;
        countOdd = 0;
        countTwo = 0;
        countZero = 0;
        
        for (int i = 0; i < n; i++) {
            cin >> curr;
            if (curr%2 == 1) {
                countOdd++;
            } else if (curr%4 == 2) {
                countTwo++;
            } else {
                countZero++;
            }
        }
        
        cout << max(max(countOdd, countTwo), countZero) << endl;
    }
    
    return 0;
}
