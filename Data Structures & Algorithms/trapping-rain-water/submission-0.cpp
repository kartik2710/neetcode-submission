class Solution {
public:
    int trap(vector<int>& arr) {
        int res=0;
         for (int i = 1; i < arr.size() - 1; i++) {

        // Find the maximum element on its left
        int left = arr[i];
        for (int j = 0; j < i; j++)
            left = max(left, arr[j]);

        // Find the maximum element on its right
        int right = arr[i];
        for (int j = i + 1; j < arr.size(); j++)
            right = max(right, arr[j]);

        // Update the maximum water
        cout<<min(left, right) - arr[i]<<"..";
        res += (min(left, right) - arr[i]);
    }

    return res;
    }
};
