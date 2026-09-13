#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, a, b, c, d, numberInFront;
    
    cin >> t;
    
    while (t--) {
        numberInFront = 0;
        cin >> a >> b >> c >> d;
        
        if (b > a) numberInFront++;
        if (c > a) numberInFront++;
        if (d > a) numberInFront++;
        
        cout << numberInFront << endl;
    }

    return 0;
}
