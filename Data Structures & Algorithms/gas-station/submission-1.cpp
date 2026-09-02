class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int currGas=0,strt=0;
        int totalgas=0, totalcost=0;

        for(int i=0; i<n; i++) totalgas+=gas[i], totalcost+=cost[i];
        if(totalcost>totalgas) return -1;

        for(int i=0; i<n; i++)
        {
            currGas+=gas[i]-cost[i];

            if(currGas<0)
            {
                strt=i+1;
                currGas=0;
            }
        }
        return strt;
    }
};
