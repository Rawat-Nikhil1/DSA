class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;

        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        int maxSum = sum;

        int low = 0;
        int high = k;

        while (high < n) {
            sum = sum - nums[low] + nums[high];
            maxSum = max(maxSum, sum);
            low++;
            high++;
        }

        return (double)maxSum / k;
    }
};