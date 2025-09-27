class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        st.push(0);
        for(int i=0; i<s.size(); i++){
            char c  = s[i];
            if(c =='('){
                st.push(0);
                
            }
            else{
                int v = st.top(); 
                st.pop();
                int w = st.top();
                st.pop();
                st.push(w + max(2*v,1));
            }
        }
        return st.top();
    }
};