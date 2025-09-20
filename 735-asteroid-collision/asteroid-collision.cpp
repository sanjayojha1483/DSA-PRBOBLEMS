class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int i = 0; i < asteroids.size(); i++) {
            int a = asteroids[i];
            bool alive = true;

            while (alive && !st.empty() && st.top() > 0 && a < 0) {
                if (st.top() < -a) {
                    st.pop(); // stack asteroid smaller → destroyed
                } else if (st.top() == -a) {
                    st.pop(); // both same → both destroyed
                    alive = false;
                } else {
                    alive = false; // current asteroid destroyed
                }
            }

            if (alive) {
                st.push(a);
            }
        }

        vector<int> ans(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};
