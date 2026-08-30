class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;

        int low = 0;
        int high = k - 1;
        long long sum = 0;
        long long maxSum = 0;

        for (int i = 0; i <= high; i++) {
            mpp[nums[i]]++;
            sum = sum + nums[i];
        }

        if (mpp.size() == k) {
            maxSum = sum;
        }

        while (high < n) {
            low++;
            high++;
            sum = sum - nums[low - 1];
            mpp[nums[low - 1]]--;
            if (mpp[nums[low - 1]] == 0) {
                mpp.erase(nums[low - 1]);
            }

            if (high >= n) {
                break;
            }
            sum = sum + nums[high];
            mpp[nums[high]]++;
            
            if (mpp.size() == k) {
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum;
    }
};