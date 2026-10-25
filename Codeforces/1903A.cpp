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
    // n boxes have a number a_i on them.
    // Machine can only reverse a subarray of boxes with length at most k.
    // Is it possible to sort the boxes in non-decreasing order?
    // Reverse subarray: choose 1 ≤ i ≤ j ≤ n. Change a_1,a_2,...,a_n to a_1,a_2,...,a_{i-1},
    // a_j,a_{j-1},...,a_i,a_{j+1},...,a_{n-1},a_n. The length of the subarray is then j - i + 1.
    
    // Test Case 1: n = 3, k = 2, a = [1,2,3].
    // The array is already sorted in non-decreasing order.
    
    // Test Case 2: n = 3, k = 1, a = [9,9,9].
    // The array is already sorted in non-decreasing order.
    
    // Test Case 3: n = 4, k = 4, a = [6,4,2,1].
    // We can reverse the whole array to get a = [1,2,4,6], which is sorted in non-decreasing
    // order.
    
    // Test Case 4: n = 4, k = 3, a = [10,3,830,14].
    // a = [10,3,830,14]->[3,10,830,14]->[3,10,14,830], which is sorted in non-decreasing order.
    
    // Test Case 5: n = 2, k = 1, a = [3, 1].
    // It is impossible to change the positions of elements with the machine since k = 1.
    
    // If k ≥ 2, we can use bubble sort to sort the array.
    // If k = 1, we can't do anything to the array, so it is only possible to sort the array
    // if the array is already sorted.
    
    int t, n, k, curr;
    bool flag;
    vector <int> a;
    cin >> t;
    
    while (t--) {
        a.clear();
        cin >> n >> k;
        for (int i = 0; i < n; i++) cin >> curr, a.pb(curr);
        flag = true;
        if (k == 1) {
            for (int i = 1; i < n; i++) {
                if (a[i] < a[i - 1]) flag = false;
            }
        }
        
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
