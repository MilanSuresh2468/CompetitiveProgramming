#include <bits/stdc++.h>
using namespace std;

int main() {
    int a_1, a_2, a_3, a_4, total = 0;
    string s;
    cin >> a_1 >> a_2 >> a_3 >> a_4 >> s;
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1') {
            total += a_1;
        } else if (s[i] == '2') {
            total += a_2;
        } else if (s[i] == '3') {
            total += a_3;
        } else {
            total += a_4;
        }
    }
    
    cout << total;

    return 0;
}
