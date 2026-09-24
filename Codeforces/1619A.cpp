#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    string s;
    bool flag;
    
    cin >> t;
    while (t--) {
        cin >> s;
        flag = true;
        
        if (s.length()%2 == 1) flag = false;
        
        for (int i = 0; i < s.length()/2; i++) {
            if (s[i] != s[s.length()/2 + i]) flag = false;
        }
        
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
