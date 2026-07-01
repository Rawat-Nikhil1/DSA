class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum = sum + nums[i];
        }

        int left = 0;
        for (int i = 0; i < n; i++) {
            int right = sum - left - nums[i];
            int diff = abs(left - right);
            ans[i] = diff;

            left = left + nums[i];
        }
        return ans;
    }
};