#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, ACount, BCount;
    string s;
    
    cin >> t;
    
    while (t--) {
        ACount = 0;
        BCount = 0;
        cin >> s;
        
        for (int i = 0; i < 5; i++) {
            if (s[i] == 'A') ACount++;
            else BCount++;
        }
        
        if (ACount < BCount) cout << "B\n";
        else cout << "A\n";
    }

    return 0;
}
