#include <bits/stdc++.h>
using namespace std;

// Type Aliases 
using ll = long long;
using db = long double;
using str = string;

// Vectors
//#define sort(x) sort(begin(x), end(x))
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
    int t, n, curr, prev;
    vector <int> a, toReturn;
    cin >> t;
    
    // High-Level Idea for Algorithm:
    // While there are numbers left to put in array:
    // ->Take 1 of each number starting from the biggest
    // and ending at the smallest
    
    while (t--) {
        cin >> n;
        toReturn.clear();
        a.clear();
        
        for (int i = 0; i < n; i++) {
            cin >> curr;
            a.push_back(curr);
        }
        sort(a.begin(), a.end(), greater<int>());
        
        while (a.size() > 0) {
            prev = -1;
            for (int i = 0; i < a.size(); i++) {
                if (a[i] != prev) {
                    toReturn.push_back(a[i]);
                    prev = a[i];
                    erase(a, i);
                    i--;
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            cout << toReturn[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
