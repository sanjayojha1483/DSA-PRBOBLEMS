class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int total = numBottles;   // initially drink all bottles
        int empties = numBottles; // all become empty

        while (empties >= numExchange) {
            // exchange empties for 1 full bottle
            empties -= numExchange;
            total += 1;         // drink that bottle
            empties += 1;       // it becomes empty
            numExchange += 1;   // cost increases
        }

        return total;
    }
};
