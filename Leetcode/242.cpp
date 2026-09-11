class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<char> sChars(200), tChars(200);
        if (s.length() != t.length()) return false;

        for (int i = 0; i < s.length(); i++) {
            sChars[s[i]]++;
            tChars[t[i]]++;
        }

        for (int i = 0; i < 200; i++) {
            if (sChars[i] != tChars[i]) return false;
        }

        return true;
    }
};
