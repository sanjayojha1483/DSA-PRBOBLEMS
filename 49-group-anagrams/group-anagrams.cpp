#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        // Step 1: Traverse all strings
        for (int i = 0; i < strs.size(); i++) {
            string word = strs[i];
            sort(word.begin(), word.end()); // sorted version
            mp[word].push_back(strs[i]);    // group by sorted key
        }

        // Step 2: collect all groups
        vector<vector<string>> result;
        unordered_map<string, vector<string>>::iterator it;
        for (it = mp.begin(); it != mp.end(); it++) {
            result.push_back(it->second);
        }

        return result;
    }
};
