class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        const long long MOD = 1000000007;
        int n = complexity.size();

        // Check if all computers besides 0 have complexity > complexity[0]
        for (int i = 1; i < n; i++) {
            if (complexity[i] <= complexity[0])
                return 0;
        }

        // If safe, number of ways = (n-1)! modulo MOD
        long long ans = 1;
        for (int i = 1; i < n; i++) {
            ans = (ans * i) % MOD;
        }

        return (int)ans;
    }
};
