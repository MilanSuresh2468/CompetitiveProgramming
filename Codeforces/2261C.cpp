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
bool isPrime(ll n) {
    for (ll i = 2; i <= sqrt(n); i++) {
        if (n%i == 0) return false;
    }
    return true;
}

int intPow(ll x, ll y) {
    ll result = 1;
    for (int i = 0; i < y; i++) result *= x;
    return result;
}


int main() {
    // Input:
    // Line 1: t (1 ≤ t ≤ 10^4).
    // Each test case:
    // Line 1: n (1 ≤ n ≤ 10^6).
    // Line 2: a_1 a_2 ... a_n (1 ≤ a_i ≤ 10^6).
    // The sum of n over all test cases ≤ 10^6. 
    // Valid moves either remove exactly one element or remove elements with an even sum.
    // The player who faces an empty array loses.
    // Determine which player has a winning strategy. 
    // Moggity starts first.
    // Output:
    // Each test case: "Moggity" if Moggity wins or "Larpity" if Larpity wins.
    
    // If the elements add up to an even sum, Moggity can remove all of those at once and win.
    
    // Analyze specific cases: 
    // 1. There is one odd element and five even elements. 
    // If Moggity picks four even elements, then Larpity must pick an even element or an odd 
    // element. This leaves Moggity with one element left that he can pick, which leaves Larpity
    // with an empty array. This means Moggity wins.
    // 2. There are 2k+1 odd elements and 2j even elements. 
    // Moggity can pick the 2j even elements. Then Larpity must either pick 1 odd element 
    // or 2k odd elements. This leaves Moggity with either 1 or 2k odd elements, which he can pick 
    // to cause Larpity to lose due to having an empty array.
    // 3. There are 2k+1 odd elements and 1 even element. 
    // Moggity can pick 2k odd elements.
    // Larpity must pick 1 element.
    // Moggity can pick 1 element.
    // Larpity has no elements to pick, so he loses. 
    
    // Simpler Version of the Problem: Every a_i is even. 
    // Moggity can pick every element on his turn, leaving Larpity with an empty array on his turn.
    // Thus, Moggity wins. 
    // ->Takeaway: If a player either has all even elements or just a single odd element left on his 
    // turn, he wins. 
    
    // Count the number of odd elements and the number of even elements.
    // Case 1: Even number of odd elements - Moggity wins.
    // Moggity wins if there is an even number of odd elements. He can remove all of the elements
    // in one turn.
    // Moggity wins if there is only one element. 
    // Moggity wins if there is an odd number of odd elements and at least 2 even elements. 
    
    // Official Solution: 
    // Represent every game state with (E,O) where E is the number of even integers and O is the
    // number of odd integers. 
    // Firstly, one can observe that Larpity wins when the input is in state (1,1) or (0,3).
    // ->(1,1): Moggity picks an element, and then Larpity picks an element. Larpity wins. 
    // ->(0,3): Moggity must pick either one or two odd integers, leaving Larpity to pick 
    // either two or one odd integers. Moggity then has no elements.
    
    // Then, one can show that in other cases, Moggity wins.
    // ->O is even. Moggity can remove the entire array and win.
    // ->O = 1. If E = 0, Moggity can remove the odd integer to win. If E ≥ 2, Moggity can remove 
    // E - 1 even integers to win.
    // ->O = 3. If E ≥ 1, Moggity can remove all even integers. Larpity must remove either one 
    // or two odd integers. Moggity can then remove either two or one odd integers respectively. 
    // Moggity wins.
    // ->O ≥ 5: Moggity can remove all even integers and O - 3 odd integers. Larpity must pick either 
    // one or two odd integers, which means Moggity can remove either two or one odd integers 
    // respectively. Moggity wins. 
    
    // Thus, Larpity wins i.f.f. there is one even integer and one integer, or there are zero even 
    // integers and three odd integers. 
    
    // The time complexity is O(n) because the program must scan over all elements and count the 
    // number of odd elements and the number of even elements. 
    
    cin.tie(0);
    
    int t, n, curr, evenCount, oddCount;
    cin >> t;
    
    while (t--) {
        cin >> n;
        oddCount = 0;
        evenCount = 0;
        
        while (n--) {
            cin >> curr;
            if (curr%2 == 0) evenCount++;
            else oddCount++;
        }
        
        if ((evenCount == 1 && oddCount == 1) || (evenCount == 0 && oddCount == 3)) {
            cout << "Larpity\n";
        } else {
            cout << "Moggity\n";
        }
    }
}
