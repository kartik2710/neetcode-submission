class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        for(int i=0; i<n; i++)
        {
            int j=i,count=0,total=0;
            while(count<n)
            {
                j=j%n;
                 total+=gas[j]-cost[j];
                if(total<0)
                break;
                j++,count++;
            }
            if(count==n) return i;

        }

        return -1;
    }
};
