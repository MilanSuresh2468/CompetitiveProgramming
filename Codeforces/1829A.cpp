#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, difs; 
    string s, base = "codeforces";
    
    cin >> t;
    
    while (t--) {
        cin >> s;
        difs = 0;
        for (int i = 0; i < 10; i++) {
            if (s[i] != base[i]) difs++;
        }
        
        cout << difs << endl;
    }
    return 0;
}
