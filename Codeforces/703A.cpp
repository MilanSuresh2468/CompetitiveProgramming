#include <bits/stdc++.h>
using namespace std;

int main() {
    int mCount = 0, cCount = 0, n, m_i, c_i;
    cin >> n;
    
    while (n--) {
        cin >> m_i >> c_i;
        if (m_i > c_i) mCount++;
        else if (c_i > m_i) cCount++;
    }
    
    if (mCount > cCount) {
        cout << "Mishka";
    } else if (mCount == cCount) {
        cout << "Friendship is magic!^^";
    } else {
        cout << "Chris";
    }
    return 0;
}
