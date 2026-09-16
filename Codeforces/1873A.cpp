#include <bits/stdc++.h>
using namespace std;

int main() {
    // three card with letters a, b, c are placed in some order
    // can do the following operation at most once:
    // ->pick two cards and swap them.
    // MISTAKE -> I ORIGINALLY THOUGHT THAT I COULD ONLY SWAP TWO ADJACENT CARDS.
    // THIS IS WRONG. I CAN SWAP ANY TWO CARDS. I SHOULD HAVE READ THE PROBLEM MORE
    // CLOSELY.
    // Is it possible to make the row become abc?
    
    // Case 1: b in middle
    // Possibilities: abc, cba
    // abc -> abc -> YES
    // cba -> (c)b(a) - > abc -> YES
    
    // Case 2: b at start
    // Possibilities: bac, bca
    // bac -> (b)(a)c -> abc -> YES
    // bca -> cba or bac -> NO (Cannot have b at start and a at end)
    // Case 3: b at end 
    // Possibilities: acb, cab 
    // acb -> abc -> YES
    // cab -> acb or cba -> NO (cannot have c at start and b at end)
    int t;
    string s;
    
    cin >> t;
    while (t--) {
        cin >> s;
        if (s == "bca" || s == "cab") {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}
