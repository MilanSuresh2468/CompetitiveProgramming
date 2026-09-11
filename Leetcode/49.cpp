class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groups;
        unordered_map <string, vector<string>> groupsHashMap;

        // Steps:
        // Step 1: create a hash map where the key is the count of each letter
        // and the value is a vector of the strings with that key
        // Step 2: go through every key in the hash map. Add each vector of strings to groups
        // Step 3: return groups 
        
        // Step 1
        for (int i = 0; i < strs.size(); i++) {
            string x = "00000000000000000000000000";
            string curr = strs[i];
            
            for (int j = 0; j < curr.length(); j++) {
                x[curr[j] - 97]++;
            }

            if (groupsHashMap.contains(x)) {
                groupsHashMap[x].push_back(curr);
            } else {
                vector<string> temp;
                temp.push_back(curr);
                groupsHashMap[x] = temp;
            }
        }



        // Step 2
        for (const auto& [key, value] : groupsHashMap) {
            groups.push_back(value);
        }

        // Step 3
        return groups;
    }
};
