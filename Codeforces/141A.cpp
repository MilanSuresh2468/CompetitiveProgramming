#include <bits/stdc++.h>
using namespace std;

// Type Aliases 
using ll = long long;
using db = long double;
using str = string;

// Vectors
#define sort(x) sort(begin(x), end(x))

// Algorithms
bool isPrime(int n) {
    for (int i = 2; i < sqrt(n); i++) {
        if (n%i == 0) return false;
    }
    return true;
}


int main() {
    string guestName, hostName, pileLetters;
    cin >> guestName >> hostName >> pileLetters;
    
    // Make an array keeping track of how many of each letter are in the pile.
    vector<int> pileLetterCount(26, 0);
    for (int i = 0; i < pileLetters.length(); i++) {
        pileLetterCount[pileLetters[i] - 'A']++;
    }
    
    // Make an array keeping track of how many of each letter are in the names.
    vector<int> nameLetterCount(26, 0);
    for (int i = 0; i < guestName.length(); i++) {
        nameLetterCount[guestName[i] - 'A']++;
    }
    for (int i = 0; i < hostName.length(); i++) {
        nameLetterCount[hostName[i] - 'A']++;
    }
    
    // If there is any less of a given letter in pileLetters than in nameLetterCount,
    // print "NO" and return 0.
    
    for (int i = 0; i < 26; i++) {
        if (pileLetterCount[i] > nameLetterCount[i]) {
            cout << "NO";
            return 0;
        }
    }
    
    
    // If there will be extra letters, print "NO".
    if ((guestName.length() + hostName.length()) != pileLetters.length()) {
        cout << "NO";
        return 0;
    }
 
    cout << "YES";
    return 0;
}
