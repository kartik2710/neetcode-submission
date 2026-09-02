class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int group) {
       if (hand.size() % group != 0) return false;

    unordered_map<int,int> freq;
    for (int x : hand) freq[x]++;

    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto &p : freq) pq.push(p.first);

    while (!pq.empty()) {
        int start = pq.top();

        for (int i = 0; i < group; i++) {
            int val = start + i;
            if (freq[val] == 0) return false;

            freq[val]--;
            if (freq[val] == 0 && val == pq.top()) {
                pq.pop();
            }
        }
    }
    return true;



    }
};
