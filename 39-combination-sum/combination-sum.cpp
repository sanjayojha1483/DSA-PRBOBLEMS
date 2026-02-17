class Solution {
public:
    
    void backtrack(vector<int>& candidates, int target, 
                   vector<int>& current, int index, 
                   vector<vector<int>>& result) {
        
        // Base case
        if(target == 0) {
            result.push_back(current);
            return;
        }
        
        if(target < 0) return;
        
        for(int i = index; i < candidates.size(); i++) {
            
            current.push_back(candidates[i]);
            
            // same index allowed (unlimited use)
            backtrack(candidates, target - candidates[i], 
                      current, i, result);
            
            current.pop_back();  // backtrack
        }
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> result;
        vector<int> current;
        
        backtrack(candidates, target, current, 0, result);
        
        return result;
    }
};
