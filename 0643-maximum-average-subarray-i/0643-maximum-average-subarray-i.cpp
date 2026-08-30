class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        int maxSum = INT_MIN;

        int high = k - 1;
        int low = 0;

        for (int i = 0; i <= high; i++) {
            sum = sum + nums[i];
        }

        while (high < n) {
            maxSum = max(maxSum, sum);
            low++;
            high++;
            sum = sum - nums[low - 1];
            if (high >= n) {
                break;
            }
            sum = nums[high] + sum;
        }

        return (double)maxSum / k;
    }
};