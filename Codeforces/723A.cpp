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
    // First friend lives at x_1. Second friend lives at x_2. Third friend lives at x_3.
    // Ox is a straight line that they live on. 
    // They need to meet at one point.
    // What is the minimum total distance they have to travel in order to meet at 
    // a point? 
    
    
    // They are only 100 possible points that they can meet at, so brute force is 
    // feasible.
    
    int x_1, x_2, x_3, curr, minDistance = 297;
    
    cin >> x_1 >> x_2 >> x_3;
    
    for (int i = 1; i <= 100; i++) {
        curr = abs(i - x_1) + abs(i - x_2) + abs(i - x_3);
        if (curr < minDistance) minDistance = curr;
    }
    
    cout << minDistance;
    return 0;
}
