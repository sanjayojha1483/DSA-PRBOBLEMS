class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> result;
        int current = 1;

        for (int i = 0; i < target.size(); i++) {
            int num = target[i];

            while (current < num) {
                result.push_back("Push");
                result.push_back("Pop");
                current++;
            }

            result.push_back("Push");
            current++;
        }

        return result;
    }
};
