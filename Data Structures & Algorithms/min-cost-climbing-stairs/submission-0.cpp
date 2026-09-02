class Solution {
public:
    int sol(int index, vector<int> cost)
    {
        if(index==0) return cost[0];
        if(index==1) return cost[1];

        return cost[index]+min(sol(index-2,cost),sol(index-1,cost));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size()==1) return cost[0];
        return min(sol(cost.size()-1,cost),sol(cost.size()-2,cost));
    }
};
