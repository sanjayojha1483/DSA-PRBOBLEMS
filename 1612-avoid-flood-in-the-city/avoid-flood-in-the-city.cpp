#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, -1);
        unordered_map<int, int> lastRain; // lake → last day it rained
        set<int> dryDays;                 // days we can dry (sorted)

        for (int i = 0; i < n; ++i) {
            int lake = rains[i];
            if (lake == 0) {
                // dry day
                dryDays.insert(i);
                ans[i] = 1; // placeholder
            } else {
                // raining day
                if (lastRain.count(lake)) {
                    int prev = lastRain[lake];
                    // find smallest dry day > prev
                    auto it = dryDays.upper_bound(prev);
                    if (it == dryDays.end()) {
                        // no valid dry day — flood inevitable
                        return {};
                    }
                    int dry_day = *it;
                    ans[dry_day] = lake;
                    dryDays.erase(it);
                }
                lastRain[lake] = i;
                ans[i] = -1;
            }
        }
        // leftover dry days already have ans = 1, OK
        return ans;
    }
};

