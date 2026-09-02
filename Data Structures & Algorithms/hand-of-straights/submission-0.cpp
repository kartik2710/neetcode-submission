class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int group) {
        int n=hand.size();
        if(n%group) return false;

        unordered_map<int,int> mp;
        for(auto x: hand) mp[x]++;

        sort(hand.begin(), hand.end());

        for(auto x: hand)
        {
            if(mp[x]>0)
            {
                for(int j=x; j<x+group; j++)
                {
                    if(mp[j]==0) return false;
                    mp[j]--;
                    
                }

            }
        }
        return true;




    }
};
