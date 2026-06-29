class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int res1 = 0;
        int res2 = nums[0];
        int ans = nums[0];
        int totalSum = 0;

        for (int i = 0; i < n; i++) {
            totalSum = nums[i] + totalSum;
        }

        int bestMin = nums[0];
        for (int i = 1; i < n; i++) {
            int v1 = nums[i];
            int v2 = nums[i] + bestMin;

            bestMin = min(v1, v2);
            ans = min(ans, bestMin);
        }
        res1 = totalSum - ans;

        int bestMax = nums[0];
        for (int i = 1; i < n; i++) {
            int v1 = nums[i];
            int v2 = nums[i] + bestMax;

            bestMax = max(v1, v2);
            res2 = max(res2, bestMax);
        }
        int res = max(res1, res2);
        if (res2 < 0) {
            return res2;
        }
        return res;
    }
};