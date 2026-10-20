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
    int n, curr, l, r, scoreOfSereja = 0, scoreOfDima = 0;
    vector <int> cards;
    cin >> n;
    l = 0;
    r = n - 1;
    
    for (int i = 0; i < n; i++) {
        cin >> curr;
        cards.pb(curr);
    }
    
    for (int i = 0; i < n; i++) {
        if (cards[l] < cards[r]) {
            curr = cards[r];
            r--;
        } else {
            curr = cards[l];
            l++;
        }
        
        if (i%2 == 0) scoreOfSereja += curr;
        else scoreOfDima += curr;
    }
    
    cout << scoreOfSereja << " " << scoreOfDima;
    
    return 0;
}
