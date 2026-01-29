class Solution {
public:
    long long minimumCost(
        string source, string target,
        vector<char>& original,
        vector<char>& changed,
        vector<int>& cost
    ) {
        const long long INF = LLONG_MAX / 4;
        int n = 26;
        vector<vector<long long>> dist(n, vector<long long>(n, INF));

        // cost 0 for same character
        for (int i = 0; i < n; ++i) dist[i][i] = 0;

        // direct transformation costs
        for (int i = 0; i < original.size(); ++i) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        // Floyd-Warshall
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];

        long long ans = 0;
        for (int i = 0; i < source.size(); ++i) {
            int u = source[i] - 'a';
            int v = target[i] - 'a';
            if (u == v) continue;
            if (dist[u][v] >= INF) return -1; // impossible
            ans += dist[u][v];
        }
        return ans;
    }
};
