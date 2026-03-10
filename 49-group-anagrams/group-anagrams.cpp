class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mp;

        for(int i = 0; i < strs.size(); i++) {

            string word = strs[i];

            vector<int> count(26,0);

            for(int j = 0; j < word.size(); j++){
                count[word[j] - 'a']++;
            }

            string key = "";

            for(int k = 0; k < 26; k++){
                key += to_string(count[k]) + "#";
            }

            mp[key].push_back(word);
        }

        vector<vector<string>> ans;

        for(auto it = mp.begin(); it != mp.end(); it++){
            ans.push_back(it->second);
        }

        return ans;
    }
};