class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1){
            return s;
        }
        vector<string>rows(numRows);
        int curr = 0;
        int direction = 1;
        for(int i=0; i<s.size(); i++){
            rows[curr] +=s[i];
            if(curr == numRows-1)
            direction = -1;
            else if(curr==0)
                direction = 1;

            curr +=direction;
            
        }
            string ans = "";
            for(int i=0; i<numRows; i++){
                ans +=rows[i];
            }
        return ans;
    }
};