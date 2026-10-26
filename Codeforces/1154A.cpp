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
    // Polycarp has guessed a,b,c ≥ 0.
    // Writes down four numbers on a board in arbitrary order: their pairwise sums and
    // the sum of all three numbers. 
    // Print three guesses.
    // Idea: The biggest number is a + b + c. We can subtract the other numbers from the
    // biggest number to get the three numbers.
    
    int x_1, x_2, x_3, x_4, sum;
    cin >> x_1 >> x_2 >> x_3 >> x_4;
    
    // Find sum of all three numbers.
    sum = x_1;
    if (x_2 > sum) sum = x_2;
    if (x_3 > sum) sum = x_3;
    if (x_4 > sum) sum = x_4;
    
    if (sum - x_1) cout << sum - x_1 << endl;
    if (sum - x_2) cout << sum - x_2 << endl;
    if (sum - x_3) cout << sum - x_3 << endl;
    if (sum - x_4) cout << sum - x_4 << endl;
    return 0;
}
