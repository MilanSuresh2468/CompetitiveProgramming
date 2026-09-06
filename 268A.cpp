#include <bits/stdc++.h>
using namespace std;

int main() {
    // Comments use two backslahes, not a hashtag.
    // "// Comment" works.
    // "# Comment" does not.
    
    // When a team plays a game at home, the players use home uniforms.
    // When a team plays as a guest on somebody else's stadium the players put on 
    // the guest uniform. 
    // Exception: when the home uniform color of the host team matches the guest' uniform,
    // the host team puts on its guest uniforms too.
    // Each team has a differently colored home uniform and guest uniform.
    
    // There are n teams that take part in the national championship.
    // The championship consists of n(n-1) games. Each team invites
    // every other team to its stadium.
    
    // How many times during the championship is a host team going to put on the guest uniform?
    // The order of the games does not affect this number.
    
    // I know the colors of the home and guest uniform for each team. 
    // Each color has a different number.
    
    // First line of input: integer n (2 <= n <= 30).
    // Each following line: h_i, a_i - color of i-th team's home and guest uniforms.
    
    // Output: in a single line, print the number of games where the host team plays in a 
    // guest uniform.
    
    // Test Case 1 
    // Input:
    // 3
    // 1 2
    // 2 4 
    // 3 4 
    
    // Team 1 plays a home game against team 2 and team 3. 
    // In the first match, team 1 has a 1-colored jersey, and team 2 has a 4-colored
    // jersey. In the second match, team 1 has a 1-colored jersey, and team 2 has a 
    // 4-colored jersey. Team 1 puts on a guest jersey while hosting 0 times.
    
    // Team 2 plays home games against teams 1 and 3.
    // In the first match, team 1 has a 2-colored jersey, so team 2 must use the 
    // guest 4-colored jersey. 
    // Second match: team 3 uses a 4-colored jersey, so team 2 can use the home
    // 2-colored jersey. Team 2 puts on a guest jersey while hosting 1 time.
    
    // Team 3 plays home games against teams 1 and 2.
    // In the first match, team 1 has a 2-colored jersey, and team 3 has a 3-colored jersey.
    // In the third match, team 2 has a 4-colored jersey, and team 3 has a 3-colored jersey.
    
    // Output: 1.
    
    // Test Case 2:
    
    // 4
    // 100 42 
    // 42 100 
    // 5 42 
    // 100 5 
    
    // 100 vs. 100, 100 vs. 42, 100 vs. 5 -> 1
    // 42 vs. 42, 42 vs. 42, 42 vs. 5 -> 2
    // 5 vs. 42., 5 vs. 100, 5 vs. 5 -> 1
    // 100 vs. 42, 100 vs. 100, 100 vs. 42 -> 1 
    
    // Output: 5.
    
    // Test Case 3:
    
    // 2 
    // 1 2
    // 1 2
    
    // Team 1 (Home) vs Team 2: 1 vs. 2 -> team 1 does not have to switch jerseys.
    // Team 2 (Home) vs. Team 1: 1 vs. 2 -> team 2 does not have to switch jerseys.
    
    // Output: 0.
    
    int n, curr;
    cin >> n;
    
    vector <int> h, a; // h: home color; a: guest color
    
    for (int i = 0; i < 2*n; i++) {
        cin >> curr;
        h.push_back(curr);
        cin >> curr;
        a.push_back(curr);
    }
    
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && h[i] == a[j]) {
                count++;
            }
        }
    }
    
    cout << count;

    return 0;
}
