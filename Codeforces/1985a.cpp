#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    string a, b;
    char temp;
    
    cin >> t;
    while (t--) {
        cin >> a >> b;
        temp = a[0];
        a[0] = b[0];
        b[0] = temp;
        cout << a << " " << b << endl;
        
    }
    return 0;
}
