class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string ans, temp;
        stringstream ss(path);

        // Split by '/'
        while (getline(ss, temp, '/')) {
            if (temp == "" || temp == ".") {
                continue; // ignore empty and '.'
            } else if (temp == "..") {
                if (!st.empty()) st.pop(); // go up one dir
            } else {
                st.push(temp); // valid folder name
            }
        }

        // Build result
        while (!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }

        return ans.empty() ? "/" : ans;
    }
};

