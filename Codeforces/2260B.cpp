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
    // Month 0: x employees and y projects.
    // Month i (0 ≤ i < k): the company has x + i employees and y + i projects.
    // Each month, each employee has to do the same number of projects, and Monocarp
    // does the rest. He gives employees as much of the projects as possible. 
    // Find the total number of projects that Monocarp will complete himself over the
    // next k months.
    
    // k ≤ 10^12, so we cannot bruteforce how many projects he will need to do 
    // himself for each k. 
    // sum = y%x + (y + 1)%(x + 1) + (y + 2)%(x + 2) +...+ (y + k - 1)%(x + k - 1)
    
    // Test Case 2: x = 3, y = 10, k = 2. 
    // Month 1: 1 project. 
    // Month 2: x = 4, y = 11. 3 projects. 
    // Total: 4 projects.
    
    // Test Case 3: x = 3, y = 8, k = 6.
    // Month 1: 8%3 = 2.
    // Month 2: 9%4 = 1. 
    // Month 3: 10%5 = 0. 
    // Month 4: 11%6 = 5. 
    // Month 5: 12%7 = 5. 
    // Month 6: 13%8 = 5.  
    // Total: 18 projects.
    
    // Test Case 6: x = 8, y = 36, k = 17. 
    // Month 1: 36%8 = 4. 
    // Month 2: 37%9 = 1. 
    // Month 3: 38%10 = 8. 
    // Month 4: 39%11 = 6. 
    // Month 5: 40%12 = 4. 
    // Month 6: 41%13 = 2. 
    // Month 7: 42%14 = 0. 
    // Month 8: 43%15 = 13. 
    // Month 9: 44%16 = 12. 
    // Month 10: 45%17 = 11.
    // Month 11: 46%18 = 10. 
    // Month 12: 47%19 = 9. 
    // Month 13: 48%20 = 8. 
    // Month 14: 49%21 = 7. 
    // Month 15: 50%22 = 6. 
    // Month 16: 51%23 = 5. 
    // Month 17: 52%24 = 4. 
    // Total: 110 projects.
    
    // Observation: if y = x + 1, then Monocarp does 1 project per month (k total).
    
    // Observation: if y = x, then Monocarp does 0 projects per month (0 total).
    
    // How many projects does Monocarp complete himself if y = x + d where 0 ≤ d < x?
    // (y - x) * k projects.
    
    // Test Case: 
    // x = 4, y = 7, k = 10. 
    // Month 1: x = 7, y = 4. 3 projects.
    // Month 2: x = 8, y = 5. 3 projects. 
    // Month 3: x = 9, y = 6. 3 projects. 
    // Month 4: x = 10, y = 7. 3 projects.
    // ... 
    // Month 10: x = 16, y = 13. 3 projects. 
    // Total: 30 projects. 
    
    // How many projects does Monocarp complete himself if y = x + d where d ≥ x? 
    
    
    // Test Case (y = x + d where d = x): 
    // x = 5, y = 10, k = 5.
    // Month 1: x = 5, y = 10. 0 projects. 
    // Month 2: x = 6, y = 11. 5 projects. 
    // Month 3: x = 7, y = 12. 5 projects. 
    // Month 4: x = 8, y = 13. 5 projects. 
    // Month 5: x = 9, y = 14. 5 projects.
    // Total: 20 projects (y - x)*(k - 1)
    
    // Test Case (y = x + d where d > x): 
    // x = 5, y = 11, k = 5. 
    // Month 1: x = 5, y = 11. 1 project. 
    // Month 2: x = 6, y = 12. 0 projects. 
    // Month 3: x = 7, y = 13. 6 projects. 
    // Month 4: x = 8, y = 14. 6 projects. 
    // Month 5: x = 9, y = 15. 6 projects. 
    // 27 projects y%x + (y - x)(k - 2) 
    
    // Test Case (y = x + d where d > x):
    // x = 5, y = 12, k = 5.
    // Month 1: x = 5, y = 12. 2 projects. 
    // Month 2: x = 6, y = 13. 1 project.
    // Month 3: x = 7, y = 14. 0 projects. 
    // Month 4: x = 8, y = 15: 7 projects. 
    // Month 5: x = 9, y = 16: 7 projects
    
    // Test Case (y = x + d where d > x):
    // x = 5, y = 16, k = 10. 
    // Month 1: x = 5, y = 16. 1 project. 
    // Month 2: x = 6, y = 17. 5 projects.
    // Month 3: x = 7, y = 18. 4 projects. 
    // Month 4: x = 8, y = 19. 3 projects.
    // Month 5: x = 9, y = 20. 2 projects. 
    // Month 6: x = 10, y = 21. 1 project. 
    // Month 7: x = 11, y = 22. 0 projects.
    // Month 8: x = 12, y = 23. 11 projects.
    // Month 9: x = 13, y = 24. 11 projects.
    // Month 10: x = 14, y = 25. 11 projects.
    
    // Observation: if Monocarp repeats the same number of projects two months in a row,
    // he will only ever have to do that many projects per month. 
    
    
    ll t, x, y, k, sum;
    cin >> t;
    
    // Tutorial
    // For sufficiently large i, (y+i) will be less than 2(x + i)
    
    
    // Brute force 
    while (t--) {
        cin >> x >> y >> k;
        sum = 0;
        
        for (int i = 0; i < min(y, k); i++) {
            sum += (y + i)%(x + i);
        }
        
        sum += max(0ll, k - y) * (y - x);
        
        cout << sum << endl;
    }
    
    
    return 0;
}
