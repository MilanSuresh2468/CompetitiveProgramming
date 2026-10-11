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
    // Alice starts with a stones, and Bob starts with b stones. 
    // The third pile has c stones. 
    
    // Alice and Bob take turns, with Alice starting. The current player may take
    // any amount of stones from the third pile and add them to their own pile. 
    // If both players take 0 stones on consecutive turns, the game ends. 
    
    // Let A and B be the final numbers of stones Alice and Bob have. The score of the game
    // is |A - B|. 
    
    // Alice plays to maximize the score. Bob plays to minimize the score. If both players
    // play optimally, find the final score. 
    
    // Alice's turn: 
    // If a ≥ b, then she should take all c stones. 
    // If a < b, then she should take every stone if |(c + a) - b| > |a - b| and 0 otherwise.
    // Bob's turn: 
    // If b ≤ a, then he should take min(c, a - b) stones.
    // if b > a, then he should take no stones. 
    // End the game if two players do not take stones in a row.
    
    long long a, b, c, t, aliceTurn, bobTurn, currentTurn;
    cin >> t;
    
    while (t--) {
        cin >> a >> b >> c; 
        aliceTurn = 10E9 + 1;
        bobTurn = 10E9 + 1; 
        currentTurn = 0; 
        while (aliceTurn != 0 && bobTurn != 0) {
            if (currentTurn%2 == 0) {
                if (a >= b) a += c, c = 0, aliceTurn = c;
                else {
                    if (abs(c + a - b) > abs(a - b)) a += c, c = 0, aliceTurn = c;
                    else aliceTurn = 0;
                }
            } else {
                if (b <= a) b += min(c, a - b), c -= min(c, a - b), bobTurn = min(c, a - b);
                else bobTurn = 0;
            }
            
            currentTurn++;
        }
        
        cout << abs(a - b) << endl;
    }
    return 0;
}
