#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    string s;
    int sum1, sum2;
    
    cin >> t;
    
    while (t--) {
        cin >> s;
        sum1 = s[0] + s[1] + s[2];
        sum2 = s[3] + s[4] + s[5];
        
        if (sum1 == sum2) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
